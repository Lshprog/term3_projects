#include "hyperlinkmodel.h"

#include <QIcon>

HyperlinkModel::HyperlinkModel(QObject* parent) :
    QAbstractListModel(parent),
    links()
{
    links
              << new Hyperlink("Wiki France", "<a href=\"https://en.wikipedia.org/wiki/France\">France wiki</a>", ":/flags/fr.png")
              << new Hyperlink("Great Britain", "London", ":/flags/gb.png")
              << new Hyperlink("Japan", "Tokyo", ":/flags/jp.png")
              << new Hyperlink("United States of America", "Washington, D.C", ":/flags/us.png");
}

HyperlinkModel::~HyperlinkModel()
{
    qDeleteAll(links);
}

int HyperlinkModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return links.size();
}

void HyperlinkModel::addHyperlink(Hyperlink &link){

    QString new_url = "<a href=\""+link.link+"\">"+link.name+"</a>";
    link.link = new_url;
    beginResetModel();
    links.append(&link);
    endResetModel();

}


QVariant HyperlinkModel::data(const QModelIndex& index, int role) const
{
    const Hyperlink& link = *links.at(index.row());

    switch (role) {
    case Qt::DisplayRole:
        return link.name;

    case Qt::DecorationRole:
        return QIcon(link.description);

    case HyperlinkRoles::HyperlinkRole:
        return link.link;

    default:
        return QVariant();
        break;
    }
}
