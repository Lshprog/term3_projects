#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(1);
    this->AddRoot("Categories");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::AddRoot(QString name)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
    item->setText(0,name);
    ui->treeWidget->addTopLevelItem(item);
};


void MainWindow::on_actionSave_File_triggered()
{

}


void MainWindow::on_actionAdd_Category_triggered()
{

}


void MainWindow::on_actionImport_FIle_triggered()
{

}


void MainWindow::on_actionAdd_element_triggered()
{
    ui->Desc_text->setText("Hi");
}


void MainWindow::on_actionDelete_Element_triggered()
{

}


void MainWindow::on_actionEdit_Element_triggered()
{

}

void MainWindow::displayTree()
{

}
void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{

}

