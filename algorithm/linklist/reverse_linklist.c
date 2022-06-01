/**
 * @file reverse_linklist.c
 * 
 * @author tappat@vip.qq.com
 * @brief reverse linklist, like 1->2->3->4 to 4->3->2->1
 * @version 0.1
 * @date 2021-12-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../Playground/test_header.h"

/* 反转单向链表算法 */
LNode *reverse_linklist(LNode *node_head)
{
    LNode *pre_node;
    LNode *next_node;
    LNode *head;

    if (node_head == NULL || node_head->next == NULL) {
        return NULL;
    }

    head = node_head->next;
    pre_node = NULL;
    while (head->next != NULL) {
        next_node = head->next;
        head->next = pre_node;
        pre_node = head;
        head = next_node;
    }

    head->next = pre_node;
    node_head->next = head;
    return node_head;
}

void pr_linklist(LNode *head)
{
    LNode *p;

    p = head->next;
    while (p != NULL) {
        printf("->%d", p->data);
        p = p->next;
    }

    printf("\n");
}

LNode *add_node(int val)
{
    LNode *node;

    node = (LNode*)malloc(sizeof(LNode));
    node->data = val;
    node->next = NULL;
    return node;
}

int main()
{
    LNode *node_head;
    LNode *p;
    char c;

    p = add_node(0);
    node_head = p;
    printf("Input node values: ");
    while ((c = getchar()) != '\n') {
        if (c == ' ') {
            continue;
        }

        p->next = add_node(c - '0');
        p = p->next;
    }

    printf("Origin linklist: ");
    pr_linklist(node_head);
    node_head = reverse_linklist(node_head);
    printf("Reversed linklist: ");
    pr_linklist(node_head);
    while (node_head != NULL) {
        p = node_head;
        node_head = p->next;
        free(p);
    }

    return 0;
}
