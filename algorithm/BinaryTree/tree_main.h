#pragma once

#include <vector>

/* C style, but I don't want to use this. */
typedef struct Tnode_t
{
    struct Tnode_t *lchild;
    struct Tnode_t *rchild;
    int val;
} tree_node;

/* C++ style */
struct Tnode
{
    struct Tnode *lchild;
    struct Tnode *rchild;
    int val;
    Tnode() : lchild(nullptr), rchild(nullptr), val(0) {}
    Tnode(int x) : lchild(nullptr), rchild(nullptr), val(x) {}
};

Tnode *create_tree_by_level(std::vector<int> nums);

void pre_order_no_recursion(Tnode *root);

#ifdef C_style
/* create a new node of tree */
tree_node *new_tree_node(int val);
#endif
