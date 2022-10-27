#include "tablemodel.h"

//! [0]
TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

TableModel::TableModel(const QVector<Hyperlink> &hyperlinks, QObject *parent)
    : QAbstractTableModel(parent),
      hyperlinks(hyperlinks)
{
}
//! [0]

//! [1]
int TableModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : hyperlinks.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 3;
}
//! [1]

//! [2]
QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= hyperlinks.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        const auto &hyperlink = hyperlinks.at(index.row());

        switch (index.column()) {
            case 0:
                return hyperlink.name;
            case 1:
                return hyperlink.link;
            case 2:
                return hyperlink.description;
            default:
                break;
        }
    }
    return QVariant();
}
//! [2]

//! [3]
QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("Name");
            case 1:
                return tr("Hyperlink");
            case 2:
                return tr("Description");
            default:
                break;
        }
    }
    return QVariant();
}
//! [3]

//! [4]
bool TableModel::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        hyperlinks.insert(position, { QString(), QString() , QString()});

    endInsertRows();
    return true;
}
//! [4]

//! [5]
bool TableModel::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        hyperlinks.removeAt(position);

    endRemoveRows();
    return true;
}
//! [5]

//! [6]
bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        const int row = index.row();
        auto hyperlink = hyperlinks.value(row);

        switch (index.column()) {
            case 0:
                hyperlink.name = value.toString();
                break;
            case 1:
                hyperlink.link = value.toString();
                break;
            case 2:
                hyperlink.description = value.toString();
                break;
            default:
                return false;
        }
        hyperlinks.replace(row, hyperlink);
        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});

        return true;
    }

    return false;
}
//! [6]

//! [7]
Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}
//! [7]

//! [8]
const QVector<Hyperlink> &TableModel::getHyperlinks() const
{
    return hyperlinks;
}
//! [8]
//!

//!
//!
