#include "listmodel.h"
#include "list.h"

#include <QStringList>
#include <QIcon>
ListModel::ListModel(List * root, QObject *parent)
    : QAbstractItemModel(parent)
{
    rootItem = root;
}

ListModel::~ListModel()
{
    //sert surement à rien
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    Element *item = static_cast<Element *>(index.internalPointer());
    if(role == Qt::DecorationRole)
    {
        if(item->isList())
            return QIcon("images/icon_list.png");
        else
            return QIcon("images/icon_element.png");

    }
    if (role != Qt::DisplayRole)
        return QVariant();
    return item->getTitle();
}

Qt::ItemFlags ListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;
    return QAbstractItemModel::flags(index);
}

QVariant ListModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return (QVariant)rootItem->getTitle();

    return QVariant();
}

QModelIndex ListModel::index(int row, int column, const QModelIndex &parent)
            const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    List *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<List*>(parent.internalPointer());

    Element *childItem =  static_cast<Element *>(parentItem->child(row));
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex ListModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    List *childItem = static_cast<List *>(index.internalPointer());
    List *parentItem = childItem->getParent();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->getNumberInParentList(), 0, parentItem);
}

int ListModel::rowCount(const QModelIndex &parent) const
{
    List *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<List*>(parent.internalPointer());

    if(parentItem->isList())
        return parentItem->childCount();
    else
        return 0;
}

int ListModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

bool ListModel::hasChildren()const
{
    if(rootItem->isList() && rootItem->childCount()>0)
        return true;
    return false;
}


Element * ListModel::getElement(const QModelIndex & index)const{
    if (!index.isValid())
        return NULL;
    Element *item = static_cast<Element *>(index.internalPointer());
    return item;
}
