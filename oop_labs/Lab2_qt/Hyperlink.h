#ifndef HYPERLINK_H
#define HYPERLINK_H
#include <QString>
#include <QDesktopServices>

struct Hyperlink {
    QString name;
    QString link;
    QString description;

    Hyperlink(const QString& name, const QString& link, const QString& description) :
        name(name),
        link(link),
        description(description)
    {}
};
#endif // HYPERLINK_H
