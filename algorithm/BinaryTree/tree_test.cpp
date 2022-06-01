#include <iostream>
#include <vector>
#include "tree_main.h"

using namespace std;

int main()
{
    vector<int> nums{2, 4, 1, 5};
    Tnode *test_root = create_tree_by_level(nums);

    pre_order_no_recursion(test_root);

    return 0;
}
