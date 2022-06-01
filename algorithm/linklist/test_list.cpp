#include "../Tools_function/head_cpp.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *my_push(vector<int> &num)
{
    ListNode *head = new ListNode(0);
    ListNode *p;

    for (size_t i = 0; i < num.size(); i++) {
        p = head;
        p->val = num[i];
        head = new ListNode(0);
        head->next = p;
    }

    p = head;
    head = head->next;
    delete p;

    return head;
}

void my_pop(ListNode *head)
{
    ListNode *p;

    while (head != nullptr) {
        cout << head->val << ' ';
        p = head;
        head = head->next;
        delete p;
    }

    cout << endl;
}

int main()
{
    ListNode *head;
    vector<int>num;
    char c;

    cout << "Input num: ";
    while ((c = getchar()) != '\n') {
        if (c == ' ') {
            continue;
        }

        num.push_back(c - '0');
    }

    head = my_push(num);
    my_pop(head);

    return 0;
}
