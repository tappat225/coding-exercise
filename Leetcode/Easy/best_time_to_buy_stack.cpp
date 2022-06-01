/**
 * @file best_time_to_buy_stack.cpp
 * 
 * @author your name (you@domain.com)
 * @brief 
 *      给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格
 *      输入：[7,1,5,3,6,4]
 * 输出：5
 * 解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
 * 
 * @version 0.1
 * @date 2022-05-09
 * 
 * @copyright Copyright (c) 2022
 * 
 * @tag: 数组, 动态规划
 * @link: https://leetcode.cn/leetbook/read/2020-top-interview-questions/xo6qz3/
 * @state: passed.
 */

#include "../../Tools_function/head_cpp.h"

using namespace std;

int maxProfit(vector<int>& prices)
{
    int i = 0;
    int min_p = prices[0];
    int max_profit = 0;

    while (i < prices.size()) {
        min_p = min(prices[i], min_p);
        max_profit = max(max_profit, prices[i] - min_p);
        i++;
    }

    return max_profit;
}

