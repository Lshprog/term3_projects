#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QItemSelection>
#include <QPushButton>

#include "hyperlinkmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    HyperlinkModel hyperlinkModel;
    QPushButton *add_button;
};

#endif // MAINWINDOW_H
