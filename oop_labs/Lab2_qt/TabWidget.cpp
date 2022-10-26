#include "TabWidget.h"
#include <QSortFilterProxyModel>
#include <QDialog>

TabWidget::TabWidget(QWidget *parent):QTabWidget(parent),list(new HyperlinkModel(this)),newTab(new NewTab(this))
{
    connect(newTab, &NewTab::sendDetails,this, &TabWidget::addEntry);

    addTab(newTab,tr("Link tabs"));

    setupTabs();
}

void TabWidget::setupTabs(){
    const auto groups = {"Test1","Test2"};

    for(const QString &str : groups){
        const auto regExp = QRegularExpression(QString("^[%1].*").arg(str),
                                                       QRegularExpression::CaseInsensitiveOption);

        auto proxyModel = new QSortFilterProxyModel(this);
        proxyModel->setSourceModel(list);
        proxyModel->setFilterRegularExpression(regExp);
        proxyModel->setFilterKeyColumn(0);

        QListView *listview = new QListView;
        listview->setModel(proxyModel);
        listview->setSelectionBehavior(QAbstractItemView::SelectItems);
        listview->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listview->setSelectionMode(QAbstractItemView::SingleSelection);

        connect(listview->selectionModel(), &QItemSelectionModel::selectionChanged,
                        this, &TabWidget::selectionChanged);

                connect(this, &QTabWidget::currentChanged, this, [this, listview](int tabIndex) {
                    if (widget(tabIndex) == listview)
                        emit selectionChanged(listview->selectionModel()->selection());
                });

                addTab(listview, str);

    }
}

void TabWidget::showAddEntryDialog()
{
    AddDialog aDialog;

    if (aDialog.exec())
        addEntry(aDialog.hyperlink());
}


void TabWidget::addEntry(Hyperlink& link){
    this->list->addHyperlink(link);
}

void TabWidget::editEntry(){
    QListView *temp = static_cast<QListView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    const QModelIndexList indexes = selectionModel->selectedRows();

    QString name;
    QString link;
    QString description;
    int row = -1;

    for(const QModelIndex &index : indexes){
        row = proxy->mapToSource(index).row();
        QModelIndex nameIndex = list->index(row,0,QModelIndex());
        QVariant varName = list->data(nameIndex,Qt::DisplayRole);
        name = varName.toString();

        QModelIndex linkIndex = list->index(row,1,QModelIndex());
    }


}









