#include "DoubleWindowContainer.h"
#include <windows.h>
#include <QWindow>
#include <QTimer>
#include <TlHelp32.h>
#include <nlohmann/json.hpp>
#include <QFile>


BOOL CALLBACK enumWindowProc(HWND hWnd, LPARAM lParam)//枚举所有进程
{
	DWORD dwProcId;
	GetWindowThreadProcessId(hWnd, &dwProcId);
	const auto pInfo = reinterpret_cast<std::pair<decltype(QProcess().processId()), WId*>*>(lParam);
	if (dwProcId == pInfo->first)
	{
		auto p = GetParent(hWnd);
		auto ph = GetParent(p);
		if (ph != nullptr) {
			*pInfo->second = reinterpret_cast<WId>(ph);
			return FALSE;
		}
	}
	return TRUE;
}

WId getFirstWindowOfProcess(const QProcess&process)
{
	WId winId{};
	auto package = std::make_pair(process.processId(), &winId);
	EnumWindows(enumWindowProc, reinterpret_cast<LPARAM>(&package));
	return winId;
}

DoubleWindowContainer::DoubleWindowContainer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	QFile configFile{ "application.container.config.json" };
	nlohmann::json configJson;
	if(configFile.open(QFile::ReadOnly))
	{
		try
		{
			configJson = nlohmann::json::parse(configFile.readAll().toStdString());
		}
		catch (...)
		{}
		configFile.close();
	}
	if(configJson.empty())
	{
		configJson["leftProcessPath"] = "notepad";
		configJson["rightProcessPath"] = "notepad";
		configJson["lunchTime"] = 5000;
		configFile.open(QFile::WriteOnly);
		configFile.write(QByteArray::fromStdString(configJson.dump(4)));
		configFile.close();
	}
	
	

	leftProcess.start(QByteArray::fromStdString(configJson["leftProcessPath"]));
	rightProcess.start(QByteArray::fromStdString(configJson["rightProcessPath"]));
	
	QTimer::singleShot(configJson["lunchTime"], [=]
		{
			QWindow* leftWindow{ nullptr }, * rightWindow{ nullptr };

			if (WId winId = getFirstWindowOfProcess(leftProcess); 
				winId != NULL)
				leftWindow = QWindow::fromWinId(winId);
			if (WId winId = getFirstWindowOfProcess(rightProcess);
				winId != NULL)
				rightWindow = QWindow::fromWinId(winId);
		
			if (leftWindow != nullptr)
				ui.leftGridLayout->addWidget(leftContainer = createWindowContainer(leftWindow, this, Qt::Widget));
			if (rightWindow != nullptr)
				ui.rightGridLayout->addWidget(rightContainer = createWindowContainer(rightWindow, this, Qt::Widget));
		});
}
