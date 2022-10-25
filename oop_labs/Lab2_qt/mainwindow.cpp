#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inputhyper.h"
#include <QItemSelectionModel>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    hyperlinkModel()
{

    ui->setupUi(this);
    setWindowTitle("Model / View sample - countries");

    ui->countryListView->setModel(&hyperlinkModel);

    QItemSelectionModel* selectionModel = ui->countryListView->selectionModel();

    add_button = new QPushButton();
    connect(selectionModel, &QItemSelectionModel::selectionChanged,
            this, &MainWindow::onSelectionChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected)
{
    Q_UNUSED(deselected)

    QModelIndexList list = selected.indexes();
    const QModelIndex& index = list.first();

    QString countryName = index.data(Qt::DisplayRole).toString();
    ui->countryNameLabel->setText(countryName);

    QString countryCapital = index.data(HyperlinkModel::HyperlinkRole).toString();
    ui->countryCapitalLabel->setText(countryCapital);
    ui->countryCapitalLabel->setOpenExternalLinks(true);

}

void MainWindow::on_pushButton_clicked()
{
    inputhyper window;
    int result = window.exec();
    if(!result)
        return;


    Hyperlink* new_hyperlink = new Hyperlink(window.name(),window.hyperlink(),":/flags/fr.png");

   //int row = hyperlinkModel.rowCount();

    hyperlinkModel.addHyperlink(new_hyperlink);


   //hyperlinkModel.insertRows(row,1);

   //QModelIndex index= hyperlinkModel.index(row);

   //ui->countryListView->setCurrentIndex(index);


}

