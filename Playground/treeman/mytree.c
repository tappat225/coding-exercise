#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "tree.h"

bool is_leaf(tree_t *tree_node)
{
    return ((tree_node->lchild == NULL) && (tree_node->rchild == NULL));
}

int init_tree(tree_t **this_tree, int init_val)
{
    if (*this_tree != NULL) {
        return -1;
    }

    *this_tree = (tree_t*)malloc(sizeof(tree_t));
    (*this_tree)->val = init_val;
    return 0;
}

void add_leaf_node(tree_t **node, int val)
{
    *node = (tree_t*)malloc(sizeof(tree_t));
    (*node)->lchild = NULL;
    (*node)->rchild = NULL;
    (*node)->val = val;;
}

int add_lchild(tree_t *this_tree, int val)
{
    if (this_tree->lchild != NULL) {
        return -1;
    }

    this_tree->lchild = (tree_t*)malloc(sizeof(tree_t));
    this_tree->lchild->val = val;
    return 0;
}

int add_rchild(tree_t *this_tree, int val)
{
    if (this_tree->rchild != NULL) {
        return -1;
    }

    this_tree->rchild = (tree_t*)malloc(sizeof(tree_t));
    this_tree->rchild->val = val;
    return 0;
}

static void find_val_in_tree(tree_t *this_tree, int val, int layer, int *flag)
{
    if (this_tree == NULL || *flag == 1) {
        return;
    }

    printf("node val = %d, layer = %d\n", this_tree->val, layer);

    if (this_tree->val == val) {
        printf("node found, layer: %d\n", layer);
        *flag = 1;
        return;
    }

    find_val_in_tree(this_tree->lchild, val, ++layer, flag);
    find_val_in_tree(this_tree->rchild, val, ++layer, flag);
}

void find_val(tree_t *this_tree, int val, int *flag)
{
    find_val_in_tree(this_tree, val, 0, flag);
}

void delete_tree_node(tree_t *node)
{
    if (node == NULL) {
        return;
    }

    free(node);
    node = NULL;
}

/* delete every node in tree */
void destory_tree(tree_t *this_node)
{
    if (this_node == NULL) {
        return;
    }

    if (this_node->lchild != NULL) {
        destory_tree(this_node->lchild);
    }

    if (this_node->rchild != NULL) {
        destory_tree(this_node->rchild);
    }

    free(this_node);
    // this_node == NULL;
}

/* qucik tree build, small value on the left, big value on the right. */
void quick_tree_add(tree_t **this_node, int val)
{
    if (*this_node == NULL) {
        add_leaf_node(this_node, val);
        return;
    }

    if ((*this_node)->val > val) {
        quick_tree_add(&((*this_node)->lchild), val);
    } else {
        quick_tree_add(&((*this_node)->rchild), val);
    }
}

/* return the pointer to the new node */
static tree_t *add_node(int val)
{
    tree_t *new_node;

    new_node = (tree_t*)malloc(sizeof(tree_t));
    if (new_node == NULL) {
        printf("allocate new node fail.\n");
        return NULL;
    }

    // printf("new node val = %d\n", val);
    new_node->val = val;
    new_node->lchild = NULL;
    new_node->rchild = NULL;

    return new_node;
}

void quick_tree_add_2(tree_t **node, int val)
{
    if (*node == NULL) {
        *node = add_node(val);
        return;
    }

    if ((*node)->val > val) {
        quick_tree_add_2(&((*node)->lchild), val);
    } else {
        quick_tree_add_2(&((*node)->rchild), val);
    }
}

/* search value in a sorted quick tree. */
void quick_search(tree_t *root, int val)
{
    int layer;

    layer = 0;
    while (root != NULL) {
        printf("debug, node val = %d\n", root->val);
        if (root->val == val) {
            printf("node found: layer = %d.\n", layer);
            break;
        }

        if (is_leaf(root) == true) {
            printf("node not found.\n");
            break;
        }

        if (root->val > val) {
            root = root->lchild;
        } else {
            root = root->rchild;
        }

        layer++;
    }
}
