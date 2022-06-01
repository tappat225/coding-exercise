/**
 * 
 * State: Unresovled.
 * Tags: 双指针
 * Link: https://www.nowcoder.com/questionTerminal/dee0bcab26a648ad9999bc891d460034?answerType=1&f=discussion
 */


#include "../Tools_function/head_cpp.h"

using namespace std;

int contain_water(vector<int> nums)
{
    int total_contain = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i + 1] < nums[i] && nums[i + 1] < nums[i + 2]) {
            total_contain += 2 * min(nums[i], nums[i + 2]);
            i++;
            continue;
        }

        total_contain += min(nums[i], nums[i + 1]);
    }

    return total_contain;
}

int main()
{
    vector<int> high;
    int test_num;
    int plank_num;
    int num;

    cin >> test_num;
    while(test_num > 0) {
        cin >> plank_num;
        while (plank_num > 0) {
            cin >> num;
            high.push_back(num);
            plank_num--;
        }
        
        cout << contain_water(high) << endl;
        high.clear();
        high.resize(0);
        test_num--;
    }

    return 0;
}
