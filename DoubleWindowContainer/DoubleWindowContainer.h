#pragma once

#include <QProcess>
#include <QtWidgets/QMainWindow>
#include "ui_DoubleWindowContainer.h"

class DoubleWindowContainer : public QMainWindow
{
    Q_OBJECT

public:
    DoubleWindowContainer(QWidget *parent = Q_NULLPTR);
    QProcess leftProcess;
    QProcess rightProcess;
private:
    QWidget* leftContainer{ nullptr }, * rightContainer{ nullptr };
    Ui::DoubleWindowContainerClass ui;
};
