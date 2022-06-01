#include <stdio.h>
#include <stdlib.h>

typedef struct link_node_t
{
    int val;
    struct link_node_t *next;
} link_node;

/* 新增一个节点 */
link_node *build_node(int val)
{
    link_node *new_node;

    new_node = (link_node*)malloc(sizeof(link_node));
    if (new_node == NULL) {
        printf("alloc new node failed.\n");
        return NULL;
    }

    new_node->next = NULL;
    new_node->val = 0;

    return new_node;
}

/* 单链表查找某个元素并返回该节点指针 */
link_node *find_node(link_node *head, int val)
{
    link_node *p;

    p = head;
    while (p != NULL) {
        if (p->val == val) {
            break;
        }

        p = p->next;
    }

    return p;
}

/* 销毁单链表 */
void destroy_link_list(link_node **head)
{
    link_node *tmp;

    while (*head != NULL) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }

    *head = NULL;
}
