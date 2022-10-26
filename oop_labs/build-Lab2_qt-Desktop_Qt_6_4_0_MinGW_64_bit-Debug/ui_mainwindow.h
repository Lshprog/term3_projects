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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *leftLayout;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QWidget *tab;
    QLabel *titleCountriesLabel;
    QListView *countryListView;
    QWidget *layoutWidget;
    QVBoxLayout *rightLayout;
    QLabel *titleDetailsLabel;
    QFormLayout *countryDetailsLayout;
    QLabel *formNameLabel;
    QLabel *countryNameLabel;
    QLabel *formCapitalLabel;
    QLabel *countryCapitalLabel;
    QTextBrowser *textBrowser;
    QLabel *formDescriptionLabel;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1034, 593);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        leftLayout = new QVBoxLayout();
        leftLayout->setSpacing(6);
        leftLayout->setObjectName("leftLayout");
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        titleCountriesLabel = new QLabel(tab);
        titleCountriesLabel->setObjectName("titleCountriesLabel");
        titleCountriesLabel->setGeometry(QRect(60, 20, 250, 50));
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
        countryListView = new QListView(tab);
        countryListView->setObjectName("countryListView");
        countryListView->setGeometry(QRect(60, 100, 250, 371));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(countryListView->sizePolicy().hasHeightForWidth());
        countryListView->setSizePolicy(sizePolicy1);
        countryListView->setMaximumSize(QSize(250, 16777215));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(620, 0, 341, 511));
        rightLayout = new QVBoxLayout(layoutWidget);
        rightLayout->setSpacing(6);
        rightLayout->setContentsMargins(11, 11, 11, 11);
        rightLayout->setObjectName("rightLayout");
        rightLayout->setContentsMargins(0, 0, 0, 0);
        titleDetailsLabel = new QLabel(layoutWidget);
        titleDetailsLabel->setObjectName("titleDetailsLabel");
        titleDetailsLabel->setMinimumSize(QSize(0, 50));
        titleDetailsLabel->setFont(font);
        titleDetailsLabel->setAlignment(Qt::AlignCenter);

        rightLayout->addWidget(titleDetailsLabel);

        countryDetailsLayout = new QFormLayout();
        countryDetailsLayout->setSpacing(6);
        countryDetailsLayout->setObjectName("countryDetailsLayout");
        countryDetailsLayout->setContentsMargins(0, -1, -1, -1);
        formNameLabel = new QLabel(layoutWidget);
        formNameLabel->setObjectName("formNameLabel");
        QFont font1;
        font1.setPointSize(12);
        formNameLabel->setFont(font1);

        countryDetailsLayout->setWidget(0, QFormLayout::LabelRole, formNameLabel);

        countryNameLabel = new QLabel(layoutWidget);
        countryNameLabel->setObjectName("countryNameLabel");

        countryDetailsLayout->setWidget(0, QFormLayout::FieldRole, countryNameLabel);

        formCapitalLabel = new QLabel(layoutWidget);
        formCapitalLabel->setObjectName("formCapitalLabel");
        formCapitalLabel->setFont(font1);

        countryDetailsLayout->setWidget(1, QFormLayout::LabelRole, formCapitalLabel);

        countryCapitalLabel = new QLabel(layoutWidget);
        countryCapitalLabel->setObjectName("countryCapitalLabel");

        countryDetailsLayout->setWidget(1, QFormLayout::FieldRole, countryCapitalLabel);

        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName("textBrowser");

        countryDetailsLayout->setWidget(2, QFormLayout::FieldRole, textBrowser);

        formDescriptionLabel = new QLabel(layoutWidget);
        formDescriptionLabel->setObjectName("formDescriptionLabel");
        formDescriptionLabel->setFont(font1);

        countryDetailsLayout->setWidget(2, QFormLayout::LabelRole, formDescriptionLabel);


        rightLayout->addLayout(countryDetailsLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        rightLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        rightLayout->addWidget(pushButton);

        tabWidget->addTab(tab, QString());

        leftLayout->addWidget(tabWidget);


        horizontalLayout->addLayout(leftLayout);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        titleCountriesLabel->setText(QCoreApplication::translate("MainWindow", "Your hyperlinks", nullptr));
        titleDetailsLabel->setText(QCoreApplication::translate("MainWindow", "Details", nullptr));
        formNameLabel->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        countryNameLabel->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        formCapitalLabel->setText(QCoreApplication::translate("MainWindow", "Link", nullptr));
        countryCapitalLabel->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        formDescriptionLabel->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
