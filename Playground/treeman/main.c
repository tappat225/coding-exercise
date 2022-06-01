#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void clear_window()
{
    system("clear");
}

int main()
{
    char usr_mode;
    int usr_val;
    tree_t *root_node;
    int node_flag;

    root_node=(tree_t*)malloc(sizeof(tree_t));
    root_node->lchild = NULL;
    root_node->rchild = NULL;
    root_node->val = 50;
    // quick_tree_add(&root_node, 32);
    // quick_tree_add(&root_node, 89);
    // quick_tree_add(&root_node, 17);
    quick_tree_add_2(&root_node, 32);
    quick_tree_add_2(&root_node, 89);
    quick_tree_add_2(&root_node, 17);
    node_flag = 0;
    // find_val(root_node, 17, &node_flag);
    quick_search(root_node, 17);
    destory_tree(root_node);

    // if (node_flag == 0) {
    //     printf("node not found.\n");
    // }
    // while((usr_input = getchar()) != EOF) {
    //     switch (usr_input) {
    //     case '1':
    //         /* code */
    //         break;
        
    //     default:
    //         exit;
    //         break;
    //     }
    // }

    return 0;
}
