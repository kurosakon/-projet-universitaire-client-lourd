#ifndef TREE_H
#define TREE_H

#include "listmodel.h"

#include <QTreeView>

class Tree:public QTreeView
{
public:
    Tree(ListModel *model);
};

#endif // TREE_H
