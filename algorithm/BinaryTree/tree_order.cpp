#include <iostream>
#include <cstdio>
#include <stack>
#include "tree_main.h"

using namespace std;

/* ---------------------------------- recursion method ---------------------------------- */

void pre_order_recursion(Tnode *root)
{
    if (root == NULL) {
        return;
    }

    printf("%d ", root->val);
    pre_order_recursion(root->lchild);
    pre_order_recursion(root->rchild);
}

void mid_order_recursion(Tnode *root)
{
    if (root == NULL) {
        return;
    }

    mid_order_recursion(root->lchild);
    printf("%d ", root->val);
    mid_order_recursion(root->rchild);
}

void post_order_recursion(Tnode *root)
{
    if (root == NULL) {
        return;
    }

    post_order_recursion(root->lchild);
    post_order_recursion(root->rchild);
    printf("%d ", root->val);
}

/* ---------------------------------- no recursion method ---------------------------------- */

void pre_order_no_recursion(Tnode *root)
{
    stack<Tnode*> node_s;
    Tnode *p = root;

    if (root == nullptr) {
        printf("Tree is empty.\n");
        return;
    }

    printf("Print tree with preorder: ");
    node_s.push(root);
    /*
     * Explanation:
     * 1) Create an empty stack nodeStack and push root node to stack. 
     * 2) Do the following while nodeStack is not empty. 
     * ….a) Pop an item from the stack and print it. 
     * ….b) Push right child of a popped item to stack 
     * ….c) Push left child of a popped item to stack
     * The right child is pushed before the left child to make sure that the left subtree is processed first.
     */
    while (!node_s.empty()) {
        p = node_s.top();
        printf("%d ", p->val);
        node_s.pop();
        if (p->rchild != nullptr) {
            node_s.push(p->rchild);
        }

        if (p->lchild != nullptr) {
            node_s.push(p->lchild);
        }
    }

    printf("\n");
}
