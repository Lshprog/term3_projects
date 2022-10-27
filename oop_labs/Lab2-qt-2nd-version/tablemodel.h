#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include <QLabel>
#include "mydelegate.h"

//! [0]

struct Hyperlink
{
    QString name;
    QString link;
    QString description;

    bool operator==(const Hyperlink &other) const
    {
        return name == other.name && link == other.link && description == other.description;
    }

};

inline QDataStream &operator<<(QDataStream &stream, const Hyperlink &hyperlink)
{
    return stream << hyperlink.name << hyperlink.link << hyperlink.description;
}

inline QDataStream &operator>>(QDataStream &stream, Hyperlink &hyperlink)
{
    return stream >> hyperlink.name >> hyperlink.link >> hyperlink.description;

}

class TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:    
    TableModel(QObject *parent = nullptr);
    TableModel(const QVector<Hyperlink> &hyperlinks, QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    const QVector<Hyperlink> &getHyperlinks() const;


private:
    QVector<Hyperlink> hyperlinks;
    MyDelegate *m_delegate;

};
//! [0]

#endif // TABLEMODEL_H
