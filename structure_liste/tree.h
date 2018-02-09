#ifndef TREE_H
#define TREE_H

#include <QTreeView>

#include "listmodel.h"

class Tree:public QTreeView
{
public:
    Tree(ListModel *model);
};

#endif // TREE_H
