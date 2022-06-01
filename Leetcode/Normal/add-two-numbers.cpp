/**
 * @file add-two-numbers.cpp
 * @author your name (you@domain.com)
 * @brief 两个链表表示的数相加，返回相加结果的链表
 * @version 0.1
 * @date 2022-05-18
 * 
 * @copyright Copyright (c) 2022
 * @link https://leetcode.cn/problems/add-two-numbers/
 * @tag: 链表
 * @state: Unresolved.
 * @Feeling 有点难度，误以为可以将链表转成数字相加再转回去，然而这数字有可能很大
 */

#include "../../Tools_function/head_cpp.h"

#include <cmath>

using namespace std;

/* Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int my_pow(int x, int y)
{
    int sum = 1;
    for (int i = 0; i < y; i++) {
        sum *= x;
    }

    return sum;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *l3 = new ListNode(0);
    ListNode *p;
    ListNode *temp;
    int num1 = 0, num2 = 0;
    int count = 0;

    p = l1;
    while (p != nullptr) {
        num1 += (pow(10, count) * p->val);
        p = p->next;
        count++;
    }

    p = l2;
    count = 0;
    while (p != nullptr) {
        num2 += (pow(10, count) * p->val);
        p = p->next;
        count++;
    }

    int total = num1 + num2;
    p = l3;
    p->val = total % 10;
    total = total / 10;
    while (total > 0) {
        temp = new ListNode(0);
        p->next = temp;
        p = p->next;
        p->val = total % 10;
        total = total / 10;
    }

    return l3;
}

void print_list(ListNode *l)
{
    ListNode *p = l;

    while(p->next != nullptr) {
        cout << p->val << ' ';
        p = p->next;
    }

    cout << p->val << endl;
}

int main()
{
    cout << my_pow(10, 2) << endl;
    return 0;
}
