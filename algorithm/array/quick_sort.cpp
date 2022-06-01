/**
 * @file quick_sort.cpp
 * @author your name (you@domain.com)
 * @brief 手撕快排---递归法与非递归法
 * @version 0.1
 * @date 2022-05-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../Tools_function/head_cpp.h"
#include <stack>
using namespace std;

#define NO_RECURSION

#ifdef NO_RECURSION

void quick_sort(vector<int> &arr)
{
    stack<int> my_s;

}

#else

/* exchange two elements without a temp val. */
void xor_exchange(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *b ^ *a;
}

void quick_sort_recursion(vector<int> &arr, int begin, int end)
{
    int lp = begin + 1;
    int rp = end;
    int base_num = arr[begin];
    int mid;

    if (lp > rp) {
        return;
    }

    while (lp < rp) {
        if ((arr[lp] > base_num) && (arr[rp] < base_num)) {
            xor_exchange(&arr[lp], &arr[rp]);
        }

        lp += (arr[lp] > base_num) ? 0 : 1;
        rp += (arr[rp] < base_num) ? 0 : -1;
    }

    mid = lp;
    if (arr[mid] < base_num) {
        xor_exchange(&arr[lp], &arr[begin]);
    }

    quick_sort_recursion(arr, begin, mid - 1);
    quick_sort_recursion(arr, mid + 1, end);
}

void quick_sort(vector<int> &arr)
{
    quick_sort_recursion(arr, 0, arr.size() - 1);
}

#endif

int main()
{
    vector<int> num;
    int a;

    printf("Input num sequence: ");
    while(cin >> a){
        num.push_back(a);//进入数组
        char c = cin.get();
        if(c == '\n')
            break;
    }

    quick_sort(num);
    cout << "Sort result: ";
    for (auto n : num) {
        cout << n << ' ';
    }

    cout << endl;
    return 0;
}
