#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include "tree_main.h"

using namespace std;

Tnode *create_tree_by_level(vector<int> nums)
{
    size_t nsize = nums.size();
    Tnode *root;
    Tnode *p;
    queue<Tnode*> q;

    if (nsize == 0) {
        return nullptr;
    }

    root = new Tnode(nums[0]);
    q.push(root);
    for (size_t i = 1; i < nsize; i += 2) {
        p = q.front();
        p->lchild = new Tnode(nums[i]);
        if (i + i < nsize) {
            p->rchild = new Tnode(nums[i + 1]);
        }

        q.pop();
        q.push(p->lchild);
        q.push(p->rchild);
    }

    return root;
}

void destory_tree(Tnode *&root)
{
    if (root == nullptr) {
        return;
    }

    if ((root->lchild == nullptr) && (root->rchild == nullptr)) {
        delete(root);
        return;
    }

    destory_tree(root->lchild);
    destory_tree(root->rchild);
}

// #define C_style
#ifdef C_style
tree_node *new_tree_node(int val)
{
    tree_node *node = (tree_node*)malloc(sizeof(tree_node));

    if (node == NULL) {
        printf("allocate tree node failed.\n");
        return NULL;
    }

    node->val = val;
    node->lchild = NULL;
    node->rchild = NULL;

    return node;
}

void destory_tree(tree_node **rt_node)
{
    if (*rt_node == NULL) {
        return;
    }

    if (((*rt_node)->lchild == NULL) && ((*rt_node)->rchild == NULL)) {
        free(rt_node);
        rt_node = NULL;
        return;
    }

    destory_tree((&(*rt_node)->lchild));
    destory_tree((&(*rt_node)->rchild));
}

tree_node *create_tree_by_level(int nums[], int nsize)
{
    tree_node *tree_root;
    tree_node *node = tree_root;
    int i;

    if (nsize < 1) {
        return NULL;
    }

    for (i = 0; i < nsize; i++) {

    }

    return tree_root;
}

#endif
