#include "tree.h"

Tree::Tree(ListModel * model):QTreeView()
{
    setModel(model);
    setHeaderHidden(true);
}
