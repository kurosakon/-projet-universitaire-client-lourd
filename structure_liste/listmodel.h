#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>

class Element;
class List;

class ListModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit            ListModel(List * root, QObject *parent = 0);
    ~ListModel();

    QVariant            data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags       flags(const QModelIndex &index) const override;
    QVariant            headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    QModelIndex         index(int row, int column,
                        const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex         parent(const QModelIndex &index) const override;
    int                 rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int                 columnCount(const QModelIndex &parent = QModelIndex()) const override;
    bool                hasChildren()const;
    Element *           getElement(const QModelIndex & index)const;


private:

    List *rootItem;
};

#endif // LISTMODEL_H
