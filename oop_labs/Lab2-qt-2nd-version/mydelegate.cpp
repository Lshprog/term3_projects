#include "mydelegate.h"

MyDelegate::MyDelegate(QObject *parent)
    : QItemDelegate{parent}
{

}
QWidget *MyDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const{
    QLabel *link_label = new QLabel(parent);
    return link_label;
}
void MyDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const{
    QString link = index.model()->data(index,Qt::DisplayRole).toString();

    QLabel *label_link = static_cast<QLabel*>(editor);
    label_link->setText(link);
    label_link->setOpenExternalLinks(true);


}
void MyDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const{
    QLabel *label_link = static_cast<QLabel*>(editor);
    model->setData(index,label_link->text(),Qt::EditRole);
};
void MyDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const {

};
