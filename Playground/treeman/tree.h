#ifndef _TREE_
#define _TREE_

typedef struct tree_node
{
    /* data */
    int val;
    struct tree_node *lchild;
    struct tree_node *rchild;
} tree_t;

int init_tree(tree_t **this_tree, int init_val);

int add_lchild(tree_t *this_tree, int val);

int add_rchild(tree_t *this_tree, int val);

void find_val(tree_t *this_tree, int val, int *flag);

void quick_tree_add(tree_t **this_node, int val);

void quick_tree_add_2(tree_t **node, int val);

void quick_search(tree_t *root, int val);

void destory_tree(tree_t *this_node);

#endif