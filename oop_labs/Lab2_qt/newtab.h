#ifndef NEWTAB_H
#define NEWTAB_H

#include <QListView>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QWidget>


class NewTab:public QWidget
{
    Q_OBJECT
public:
    NewTab(QWidget *parent = nullptr);
public slots:
    void addHyperlink();

signals:
    void sendDetails(const QString &name, const QString &link, const QString &description);
};



#endif // NEWTAB_H
