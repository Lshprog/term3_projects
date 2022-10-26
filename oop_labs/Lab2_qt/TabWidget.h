#ifndef TABWIDGET_H
#define TABWIDGET_H

#include "qitemselectionmodel.h"
#include <QTabWidget>
#include <QWidget>
#include "hyperlinkmodel.h"
#include "newtab.h"


class TabWidget : public QTabWidget
{
    Q_OBJECT
public:
    TabWidget(QWidget *parent = nullptr);
    void readFromFile(const QString &fileName);
    void writeToFile(const QString &fileName);

public slots:
    void showAddEntryDialog();
    void addEntry(Hyperlink &hyperlink);
    void editEntry();
    void removeEntry();
signals:
    void selectionChanged (const QItemSelection &selected);

private:
    void setupTabs();

    HyperlinkModel *list;
    NewTab *newTab;


};

#endif // TABWIDGET_H
