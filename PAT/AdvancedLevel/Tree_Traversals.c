/**
 * Title: 1020 Tree Traversals
 * 
 * Content:
 * Suppose that all the keys in a binary tree are distinct positive integers.
 * Given the postorder and inorder traversal sequences,
 * you are supposed to output the level order traversal sequence of the corresponding binary tree.
 * 
 * Input Specification:
 * Each input file contains one test case. For each case, the first line gives a positive integer N (≤30),
 * the total number of nodes in the binary tree.
 * The second line gives the postorder sequence and the third line gives the inorder sequence.
 * All the numbers in a line are separated by a space.
 * 
 * Output Specification:
 * For each test case, print in one line the level order traversal sequence of the corresponding binary tree.
 * All the numbers in a line must be separated by exactly one space,
 * and there must be no extra space at the end of the line.
 * 
 * Sample Input:
 * 7
 * 2 3 1 5 7 6 4
 * 1 2 3 4 5 6 7
 * Sample Output:
 * 4 1 6 3 5 7 2
 * 
 * Link: https://pintia.cn/problem-sets/994805342720868352/problems/994805485033603072
 * 
 * State: Unsolved.
 * 
 * Idea: The last node in a section of inorder sequence must be a root node,
 * check the value of this node in the postorder sequence.
 * We will find it is the node that seperates the sequence into the left and right parts of the tree.
 * Recurse this method for multiple times, then we can construct the whole tree.
 * 
 * [tips] inorder - 中序遍历, postorder - 后序遍历
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct tree_node
{
    struct tree_node *l_child;
    struct tree_node *r_child;
    int val;
}node_t;

/**
 * get position of value x in seqence.
 * 
 * @param fp: first position
 * @param lp: last position
 * 
*/
int get_postion(int *seq, int x, int fp, int lp)
{
    int i;
    for (i = fp; i <= lp; i++) {
        if (seq[i] == x) {
            return i;
        }
    }

    return -1;
}

void show_sequence(int *seq, int fp, int lp, const char *seq_name)
{
    int i;
    printf("%s: ", seq_name);
    for (i = fp; i <= lp; i++) {
        printf("%d ",seq[i]);
    }

    printf("\n");
}

int cons_tree(int *post_ord_s, int *in_ord_s, node_t *tree, int in_fp, int in_lp, int po_fp, int po_lp, int layer)
{
    int mid_p;
    int root_val = post_ord_s[po_lp];
    printf("Layer[%d]: \n", layer);
    show_sequence(post_ord_s, po_fp, po_lp, "postorder seq");
    show_sequence(in_ord_s, in_fp, in_lp, "inorder seq");
    printf("root_val = %d\n", root_val);
    if (in_fp == in_lp) {
        tree->val = root_val;
        tree->l_child = NULL;
        tree->r_child = NULL;
        return 0;
    }

    // if (in_fp > in_lp) {
    //     tree->val = -1;
    //     tree->l_child = NULL;
    //     tree->r_child = NULL;
    //     return 0;
    // }

    if ((mid_p = get_postion(in_ord_s, root_val, in_fp, in_lp)) < 0 ) {
        printf("value not found!\n");
        return -1;
    }

    printf("mid position = %d\n", mid_p);
    tree->val = root_val;
    tree->l_child = (node_t *)malloc(sizeof(node_t));
    tree->r_child = (node_t *)malloc(sizeof(node_t));
    // tree->val = post_ord_s[mid_p];
    if (cons_tree(post_ord_s, in_ord_s, tree->l_child, in_fp, mid_p - 1, po_fp, mid_p - 1, layer + 1) < 0) {
        return -1;
    }

    if (cons_tree(post_ord_s, in_ord_s, tree->r_child, mid_p + 1, in_lp, mid_p, po_lp - 1, layer + 1) < 0) {
        return -1;
    }

    return 0;
}

void print_tree_by_level(node_t *tree)
{
    if (tree == NULL) {
        printf("Empty!\n");
        return;
    }

    

}

int main()
{
    int i;
    int num;
    node_t *tree;

    num = 0;
    // printf("Input tree nodes num: ");
    scanf("%d", &num);
    int post_ord[num];
    int in_ord[num];
    // printf("Postorder: ");
    for (i = 0; i < num; i++) {
        scanf("%d", &post_ord[i]);
    }

    // printf("Inorder: ");
    for (i = 0; i < num; i++) {
        scanf("%d", &in_ord[i]);
    }

    tree = (node_t *)malloc(sizeof(node_t));
    tree->val = -1;
    tree->l_child = NULL;
    tree->r_child = NULL;
    if (cons_tree(post_ord, in_ord, tree, 0, num - 1, 0, num - 1, 1) < 0) {
        printf("Construct tree failed.\n");
        goto done;
    }

    printf("Print tree by level: \n");
    print_tree_by_level(tree);
    printf("\n");

done:
    free(tree);
    tree = NULL;
    return 0;
}
