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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionInsert_row;
    QAction *actionInsert_column;
    QAction *actionSave_File;
    QAction *actionImport_FIle;
    QAction *actionAdd_Category;
    QAction *actionAdd_element;
    QAction *actionDelete_Element;
    QAction *actionEdit_Element;
    QWidget *centralwidget;
    QTreeWidget *treeWidget;
    QLabel *Info_label;
    QLabel *Cat_label;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *Name_label;
    QLabel *Link_label;
    QLabel *Link_text;
    QLabel *Desc_label;
    QTextBrowser *Desc_text;
    QLabel *Name_text;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuActions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1288, 614);
        actionInsert_row = new QAction(MainWindow);
        actionInsert_row->setObjectName("actionInsert_row");
        actionInsert_column = new QAction(MainWindow);
        actionInsert_column->setObjectName("actionInsert_column");
        actionSave_File = new QAction(MainWindow);
        actionSave_File->setObjectName("actionSave_File");
        actionImport_FIle = new QAction(MainWindow);
        actionImport_FIle->setObjectName("actionImport_FIle");
        actionAdd_Category = new QAction(MainWindow);
        actionAdd_Category->setObjectName("actionAdd_Category");
        actionAdd_element = new QAction(MainWindow);
        actionAdd_element->setObjectName("actionAdd_element");
        actionDelete_Element = new QAction(MainWindow);
        actionDelete_Element->setObjectName("actionDelete_Element");
        actionEdit_Element = new QAction(MainWindow);
        actionEdit_Element->setObjectName("actionEdit_Element");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(50, 60, 221, 481));
        Info_label = new QLabel(centralwidget);
        Info_label->setObjectName("Info_label");
        Info_label->setGeometry(QRect(690, 50, 211, 20));
        Info_label->setStyleSheet(QString::fromUtf8("font:bold 14px;\n"
""));
        Info_label->setAlignment(Qt::AlignCenter);
        Info_label->setOpenExternalLinks(false);
        Cat_label = new QLabel(centralwidget);
        Cat_label->setObjectName("Cat_label");
        Cat_label->setGeometry(QRect(90, 20, 131, 16));
        Cat_label->setStyleSheet(QString::fromUtf8("font:bold 14px;\n"
""));
        Cat_label->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(510, 100, 531, 391));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        Name_label = new QLabel(layoutWidget);
        Name_label->setObjectName("Name_label");
        Name_label->setStyleSheet(QString::fromUtf8("font:bold 12px"));

        formLayout->setWidget(0, QFormLayout::LabelRole, Name_label);

        Link_label = new QLabel(layoutWidget);
        Link_label->setObjectName("Link_label");
        Link_label->setStyleSheet(QString::fromUtf8("font:bold 12px"));

        formLayout->setWidget(1, QFormLayout::LabelRole, Link_label);

        Link_text = new QLabel(layoutWidget);
        Link_text->setObjectName("Link_text");
        Link_text->setStyleSheet(QString::fromUtf8("color:rgb(85, 0, 255);\n"
"font: 9pt \"Arial\";\n"
"text-decoration: underline;"));
        Link_text->setOpenExternalLinks(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, Link_text);

        Desc_label = new QLabel(layoutWidget);
        Desc_label->setObjectName("Desc_label");
        Desc_label->setStyleSheet(QString::fromUtf8("font:bold 12px"));

        formLayout->setWidget(2, QFormLayout::LabelRole, Desc_label);

        Desc_text = new QTextBrowser(layoutWidget);
        Desc_text->setObjectName("Desc_text");

        formLayout->setWidget(2, QFormLayout::FieldRole, Desc_text);

        Name_text = new QLabel(layoutWidget);
        Name_text->setObjectName("Name_text");
        Name_text->setOpenExternalLinks(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, Name_text);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1288, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuActions = new QMenu(menubar);
        menuActions->setObjectName("menuActions");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuActions->menuAction());
        menuFile->addAction(actionSave_File);
        menuFile->addAction(actionImport_FIle);
        menuActions->addAction(actionAdd_Category);
        menuActions->addSeparator();
        menuActions->addAction(actionAdd_element);
        menuActions->addAction(actionDelete_Element);
        menuActions->addAction(actionEdit_Element);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionInsert_row->setText(QCoreApplication::translate("MainWindow", "Insert row", nullptr));
        actionInsert_column->setText(QCoreApplication::translate("MainWindow", "Insert column", nullptr));
        actionSave_File->setText(QCoreApplication::translate("MainWindow", "Save File", nullptr));
        actionImport_FIle->setText(QCoreApplication::translate("MainWindow", "Import File", nullptr));
        actionAdd_Category->setText(QCoreApplication::translate("MainWindow", "Add Category", nullptr));
        actionAdd_element->setText(QCoreApplication::translate("MainWindow", "Add Element", nullptr));
        actionDelete_Element->setText(QCoreApplication::translate("MainWindow", "Delete Element", nullptr));
        actionEdit_Element->setText(QCoreApplication::translate("MainWindow", "Edit Element", nullptr));
        Info_label->setText(QCoreApplication::translate("MainWindow", "Information", nullptr));
        Cat_label->setText(QCoreApplication::translate("MainWindow", "Categories", nullptr));
        Name_label->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        Link_label->setText(QCoreApplication::translate("MainWindow", "Link", nullptr));
        Link_text->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Desc_label->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        Name_text->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuActions->setTitle(QCoreApplication::translate("MainWindow", "Actions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
