#include "addresswidget.h"
#include "adddialog.h"

#include <QtWidgets>


//! [0]
AddressWidget::AddressWidget(QWidget *parent)
    : QTabWidget(parent),
      table(new TableModel(this)),
      newAddressTab(new NewAddressTab(this))
{
    connect(newAddressTab, &NewAddressTab::sendDetails,
        this, &AddressWidget::addEntry);

    addTab(newAddressTab, tr("Hyperlink Book"));
    setupTabs();
}
//! [0]

//! [2]
void AddressWidget::showAddEntryDialog()
{
    AddDialog aDialog;

    if (aDialog.exec())
        addEntry(aDialog.name(), aDialog.link(),aDialog.description());
}
//! [2]

//! [3]
void AddressWidget::addEntry(const QString &name, const QString &link, const QString &description)
{
    if (!table->getHyperlinks().contains({ name, link, description })) {
        table->insertRows(0, 1, QModelIndex());

        QModelIndex index = table->index(0, 0, QModelIndex());
        table->setData(index, name, Qt::EditRole);
        index = table->index(0, 1, QModelIndex());
        table->setData(index,link, Qt::EditRole);
        index = table->index(0 ,2, QModelIndex());
        table->setData(index, description,Qt::EditRole);

        removeTab(indexOf(newAddressTab));
    } else {
        QMessageBox::information(this, tr("Duplicate Name"),
            tr("The name \"%1\" already exists.").arg(name));
    }
}
//! [3]

//! [4a]
void AddressWidget::editEntry()
{
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    const QModelIndexList indexes = selectionModel->selectedRows();
    QString name;
    QString link;
    QString description;
    int row = -1;

    for (const QModelIndex &index : indexes) {
        row = proxy->mapToSource(index).row();
        QModelIndex nameIndex = table->index(row, 0, QModelIndex());
        QVariant varName = table->data(nameIndex, Qt::DisplayRole);
        name = varName.toString();

        QModelIndex linkIndex = table->index(row, 1, QModelIndex());
        QVariant varLink = table->data(linkIndex, Qt::DisplayRole);
        link = varLink.toString();

        QModelIndex descIndex = table->index(row, 2, QModelIndex());
        QVariant varDesc = table->data(descIndex, Qt::DisplayRole);
        description = varDesc.toString();



    }
//! [4a]

//! [4b]
    AddDialog aDialog;
    aDialog.setWindowTitle(tr("Edit a Contact"));
    aDialog.editAddress(name, link, description);

    if (aDialog.exec()) {
        const QString newLink = aDialog.link();
        const QString newDesc = aDialog.description();
        if (newLink != link) {
            const QModelIndex index = table->index(row, 1, QModelIndex());
            table->setData(index, newLink, Qt::EditRole);
        }

        if (newDesc != description) {
            const QModelIndex index = table->index(row, 2, QModelIndex());
            table->setData(index, newDesc, Qt::EditRole);
        }
    }
}
//! [4b]

//! [5]
void AddressWidget::removeEntry()
{
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    const QModelIndexList indexes = selectionModel->selectedRows();

    for (QModelIndex index : indexes) {
        int row = proxy->mapToSource(index).row();
        table->removeRows(row, 1, QModelIndex());
    }

    if (table->rowCount(QModelIndex()) == 0)
        insertTab(0, newAddressTab, tr("Desc Book"));
}
//! [5]

//! [1]
void AddressWidget::setupTabs()
{
    const auto groups = { "ABC", "DEF", "GHI", "JKL", "MNO", "PQR", "STU", "VW", "XYZ" };

    for (const QString &str : groups) {
        const auto regExp = QRegularExpression(QString("^[%1].*").arg(str),
                                               QRegularExpression::CaseInsensitiveOption);

        auto proxyModel = new QSortFilterProxyModel(this);
        proxyModel->setSourceModel(table);
        proxyModel->setFilterRegularExpression(regExp);
        proxyModel->setFilterKeyColumn(0);

        QTableView *tableView = new QTableView;
        tableView->setModel(proxyModel);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->hide();
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSortingEnabled(true);


        connect(tableView->selectionModel(), &QItemSelectionModel::selectionChanged,
                this, &AddressWidget::selectionChanged);

        connect(this, &QTabWidget::currentChanged, this, [this, tableView](int tabIndex) {
            if (widget(tabIndex) == tableView)
                emit selectionChanged(tableView->selectionModel()->selection());
        });

        addTab(tableView, str);
    }
}
//! [1]

//! [7]
void AddressWidget::readFromFile(const QString &fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
        return;
    }

    QVector<Hyperlink> hyperlinks;
    QDataStream in(&file);
    in >> hyperlinks;

    if (hyperlinks.isEmpty()) {
        QMessageBox::information(this, tr("No contacts in file"),
                                 tr("The file you are attempting to open contains no contacts."));
    } else {
        for (const auto &link: qAsConst(hyperlinks))
            addEntry(link.name, link.link, link.description);
    }
}
//! [7]

//! [6]
void AddressWidget::writeToFile(const QString &fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }

    QDataStream out(&file);
    out << table->getHyperlinks();
}
//! [6]
