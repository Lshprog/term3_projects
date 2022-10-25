#ifndef HYPERLINKMODEL_H
#define HYPERLINKMODEL_H

#include <QAbstractListModel>
#include <QVector>

#include "Hyperlink.h"

class HyperlinkModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum HyperlinkRoles {
        HyperlinkRole = Qt::UserRole,
    };

    HyperlinkModel(QObject* parent = 0);
    ~HyperlinkModel();

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    void addHyperlink(Hyperlink *link);
private:
    QVector<Hyperlink*> links;

};
#endif // HYPERLINKMODEL_H
