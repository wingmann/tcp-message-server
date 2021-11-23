/********************************************************************************
** Form generated from reading UI file 'send_receive_manager.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEND_RECEIVE_MANAGER_H
#define UI_SEND_RECEIVE_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SendReceiveManager
{
public:
    QWidget* centralWidget;
    QHBoxLayout* horizontalLayout;

    QVBoxLayout* clientVerticalBoxLayout1;
    QLabel* clientLabel1;
    QListWidget* clientListWidget1;
    QLineEdit* clientLineEdit1;

    QVBoxLayout* clientVerticalBoxLayout2;
    QLabel* clientLabel2;
    QListWidget* clientListWidget2;
    QLineEdit* clientLineEdit2;

    QVBoxLayout* serverVerticalBoxLayout;
    QLabel* serverLabel;
    QListWidget* serverListWidget;
    QLineEdit* serverLineEdit;

    QMenuBar* menuBar;
    QStatusBar* statusBar;

    void setupUi(QMainWindow* SendReceiveManager)
    {
        if (SendReceiveManager->objectName().isEmpty())
            SendReceiveManager->setObjectName(QString::fromUtf8("SendReceiveManager"));

        SendReceiveManager->resize(672, 434);

        centralWidget = new QWidget(SendReceiveManager);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));

        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        clientVerticalBoxLayout1 = new QVBoxLayout();
        clientVerticalBoxLayout1->setSpacing(6);
        clientVerticalBoxLayout1->setObjectName(QString::fromUtf8("clientVerticalBoxLayout1"));

        clientLabel1 = new QLabel(centralWidget);
        clientLabel1->setObjectName(QString::fromUtf8("clientLabel1"));

        clientVerticalBoxLayout1->addWidget(clientLabel1);

        clientListWidget1 = new QListWidget(centralWidget);
        clientListWidget1->setObjectName(QString::fromUtf8("clientListWidget1"));

        clientVerticalBoxLayout1->addWidget(clientListWidget1);

        clientLineEdit1 = new QLineEdit(centralWidget);
        clientLineEdit1->setObjectName(QString::fromUtf8("clientLineEdit1"));

        clientVerticalBoxLayout1->addWidget(clientLineEdit1);

        horizontalLayout->addLayout(clientVerticalBoxLayout1);

        clientVerticalBoxLayout2 = new QVBoxLayout();
        clientVerticalBoxLayout2->setSpacing(6);
        clientVerticalBoxLayout2->setObjectName(QString::fromUtf8("clientVerticalBoxLayout2"));

        clientLabel2 = new QLabel(centralWidget);
        clientLabel2->setObjectName(QString::fromUtf8("clientLabel2"));

        clientVerticalBoxLayout2->addWidget(clientLabel2);

        clientListWidget2 = new QListWidget(centralWidget);
        clientListWidget2->setObjectName(QString::fromUtf8("clientListWidget2"));

        clientVerticalBoxLayout2->addWidget(clientListWidget2);

        clientLineEdit2 = new QLineEdit(centralWidget);
        clientLineEdit2->setObjectName(QString::fromUtf8("clientLineEdit2"));

        clientVerticalBoxLayout2->addWidget(clientLineEdit2);

        horizontalLayout->addLayout(clientVerticalBoxLayout2);

        serverVerticalBoxLayout = new QVBoxLayout();
        serverVerticalBoxLayout->setSpacing(6);
        serverVerticalBoxLayout->setObjectName(QString::fromUtf8("serverVerticalBoxLayout"));

        serverLabel = new QLabel(centralWidget);
        serverLabel->setObjectName(QString::fromUtf8("serverLabel"));

        serverVerticalBoxLayout->addWidget(serverLabel);

        serverListWidget = new QListWidget(centralWidget);
        serverListWidget->setObjectName(QString::fromUtf8("serverListWidget"));

        serverVerticalBoxLayout->addWidget(serverListWidget);

        serverLineEdit = new QLineEdit(centralWidget);
        serverLineEdit->setObjectName(QString::fromUtf8("serverLineEdit"));

        serverVerticalBoxLayout->addWidget(serverLineEdit);

        horizontalLayout->addLayout(serverVerticalBoxLayout);

        SendReceiveManager->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SendReceiveManager);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 672, 26));
        SendReceiveManager->setMenuBar(menuBar);
        statusBar = new QStatusBar(SendReceiveManager);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SendReceiveManager->setStatusBar(statusBar);

        retranslateUi(SendReceiveManager);

        QMetaObject::connectSlotsByName(SendReceiveManager);
    } // setupUi

    void retranslateUi(QMainWindow* SendReceiveManager)
    {
        SendReceiveManager->setWindowTitle(QCoreApplication::translate("SendReceiveManager", "Network", nullptr));
        clientLabel1->setText(QCoreApplication::translate("SendReceiveManager", "Client [1]", nullptr));
        clientLabel2->setText(QCoreApplication::translate("SendReceiveManager", "Client [2]", nullptr));
        serverLabel->setText(QCoreApplication::translate("SendReceiveManager", "Server", nullptr));
    } // retranslateUi
};

namespace Ui
{

    class SendReceiveManager : public Ui_SendReceiveManager
    {
    };

} // namespace ui

QT_END_NAMESPACE

#endif // UI_SEND_RECEIVE_MANAGER_H
