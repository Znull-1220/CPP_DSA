/**
* @file      01_knapsack_1D.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     0/1 Knapsack Problem using 1D DP (滚动数组)
* @date      24-8-30
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 3;
    int bagWeight = 4;  // 样例就和代码随想录上面一致

    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};

    // dp[j]表示容量为j时 背包中物品的最大价值
    vector<int> dp(bagWeight + 1, 0);
    // 对于初始化，首先dp[0] = 0 含义明确
    // 对于idx != 0的元素，为了防止DP时被初始值覆盖，初始化为非负最小值 即0

    // 1D必须 先遍历物品再遍历背包 否则其实只放入了一件物品
    for(int i = 0; i < n; i++) {
        // 遍历背包容量必须倒序，否则可能会放入相同的两件物品，因为一维数组前面会对后面产生影响
        for(int j = bagWeight; j >= weight[i]; j--) {
            // 遍历 >= weight[i]的原因是，如果容量小于weight[i]，那么肯定放不下第i个物品
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }

        // logging
        for(const int val : dp) {
            cout << val << " ";
        }
        cout << endl;
    }
}