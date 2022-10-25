/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *leftLayout;
    QLabel *titleCountriesLabel;
    QListView *countryListView;
    QVBoxLayout *rightLayout;
    QLabel *titleDetailsLabel;
    QFormLayout *countryDetailsLayout;
    QLabel *formNameLabel;
    QLabel *countryNameLabel;
    QLabel *formCapitalLabel;
    QLabel *countryCapitalLabel;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1069, 578);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        leftLayout = new QVBoxLayout();
        leftLayout->setSpacing(6);
        leftLayout->setObjectName("leftLayout");
        titleCountriesLabel = new QLabel(centralWidget);
        titleCountriesLabel->setObjectName("titleCountriesLabel");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleCountriesLabel->sizePolicy().hasHeightForWidth());
        titleCountriesLabel->setSizePolicy(sizePolicy);
        titleCountriesLabel->setMinimumSize(QSize(0, 50));
        titleCountriesLabel->setMaximumSize(QSize(250, 16777215));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        titleCountriesLabel->setFont(font);
        titleCountriesLabel->setAlignment(Qt::AlignCenter);

        leftLayout->addWidget(titleCountriesLabel);

        countryListView = new QListView(centralWidget);
        countryListView->setObjectName("countryListView");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(countryListView->sizePolicy().hasHeightForWidth());
        countryListView->setSizePolicy(sizePolicy1);
        countryListView->setMaximumSize(QSize(250, 16777215));

        leftLayout->addWidget(countryListView);


        horizontalLayout->addLayout(leftLayout);

        rightLayout = new QVBoxLayout();
        rightLayout->setSpacing(6);
        rightLayout->setObjectName("rightLayout");
        titleDetailsLabel = new QLabel(centralWidget);
        titleDetailsLabel->setObjectName("titleDetailsLabel");
        titleDetailsLabel->setMinimumSize(QSize(0, 50));
        titleDetailsLabel->setFont(font);
        titleDetailsLabel->setAlignment(Qt::AlignCenter);

        rightLayout->addWidget(titleDetailsLabel);

        countryDetailsLayout = new QFormLayout();
        countryDetailsLayout->setSpacing(6);
        countryDetailsLayout->setObjectName("countryDetailsLayout");
        countryDetailsLayout->setContentsMargins(0, -1, -1, -1);
        formNameLabel = new QLabel(centralWidget);
        formNameLabel->setObjectName("formNameLabel");
        QFont font1;
        font1.setPointSize(12);
        formNameLabel->setFont(font1);

        countryDetailsLayout->setWidget(0, QFormLayout::LabelRole, formNameLabel);

        countryNameLabel = new QLabel(centralWidget);
        countryNameLabel->setObjectName("countryNameLabel");

        countryDetailsLayout->setWidget(0, QFormLayout::FieldRole, countryNameLabel);

        formCapitalLabel = new QLabel(centralWidget);
        formCapitalLabel->setObjectName("formCapitalLabel");
        formCapitalLabel->setFont(font1);

        countryDetailsLayout->setWidget(1, QFormLayout::LabelRole, formCapitalLabel);

        countryCapitalLabel = new QLabel(centralWidget);
        countryCapitalLabel->setObjectName("countryCapitalLabel");

        countryDetailsLayout->setWidget(1, QFormLayout::FieldRole, countryCapitalLabel);


        rightLayout->addLayout(countryDetailsLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        rightLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");

        rightLayout->addWidget(pushButton);


        horizontalLayout->addLayout(rightLayout);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        titleCountriesLabel->setText(QCoreApplication::translate("MainWindow", "Your hyperlinks", nullptr));
        titleDetailsLabel->setText(QCoreApplication::translate("MainWindow", "Details", nullptr));
        formNameLabel->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        countryNameLabel->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        formCapitalLabel->setText(QCoreApplication::translate("MainWindow", "Capital", nullptr));
        countryCapitalLabel->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
