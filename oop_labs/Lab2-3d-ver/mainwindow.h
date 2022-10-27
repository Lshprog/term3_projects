#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QVector>
#include "hyperlink.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void AddRoot(QString name);

    void displayTree();

    void on_actionSave_File_triggered();

    void on_actionAdd_Category_triggered();

    void on_actionImport_FIle_triggered();

    void on_actionAdd_element_triggered();

    void on_actionDelete_Element_triggered();

    void on_actionEdit_Element_triggered();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::MainWindow *ui;
    QVector<Hyperlink*> hyperlinks;
};
#endif // MAINWINDOW_H
