/********************************************************************************
** Form generated from reading UI file 'DoubleWindowContainer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOUBLEWINDOWCONTAINER_H
#define UI_DOUBLEWINDOWCONTAINER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoubleWindowContainerClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QWidget *leftWindowParent;
    QGridLayout *leftGridLayout;
    QWidget *rightWindowParent;
    QGridLayout *rightGridLayout;

    void setupUi(QMainWindow *DoubleWindowContainerClass)
    {
        if (DoubleWindowContainerClass->objectName().isEmpty())
            DoubleWindowContainerClass->setObjectName(QString::fromUtf8("DoubleWindowContainerClass"));
        DoubleWindowContainerClass->resize(928, 637);
        centralWidget = new QWidget(DoubleWindowContainerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        leftWindowParent = new QWidget(centralWidget);
        leftWindowParent->setObjectName(QString::fromUtf8("leftWindowParent"));
        leftWindowParent->setMinimumSize(QSize(100, 100));
        leftGridLayout = new QGridLayout(leftWindowParent);
        leftGridLayout->setSpacing(6);
        leftGridLayout->setContentsMargins(11, 11, 11, 11);
        leftGridLayout->setObjectName(QString::fromUtf8("leftGridLayout"));
        leftGridLayout->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(leftWindowParent);

        rightWindowParent = new QWidget(centralWidget);
        rightWindowParent->setObjectName(QString::fromUtf8("rightWindowParent"));
        rightWindowParent->setMinimumSize(QSize(100, 100));
        rightGridLayout = new QGridLayout(rightWindowParent);
        rightGridLayout->setSpacing(6);
        rightGridLayout->setContentsMargins(11, 11, 11, 11);
        rightGridLayout->setObjectName(QString::fromUtf8("rightGridLayout"));
        rightGridLayout->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(rightWindowParent);


        verticalLayout->addLayout(horizontalLayout);

        DoubleWindowContainerClass->setCentralWidget(centralWidget);

        retranslateUi(DoubleWindowContainerClass);

        QMetaObject::connectSlotsByName(DoubleWindowContainerClass);
    } // setupUi

    void retranslateUi(QMainWindow *DoubleWindowContainerClass)
    {
        DoubleWindowContainerClass->setWindowTitle(QCoreApplication::translate("DoubleWindowContainerClass", "DoubleWindowContainer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoubleWindowContainerClass: public Ui_DoubleWindowContainerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOUBLEWINDOWCONTAINER_H
