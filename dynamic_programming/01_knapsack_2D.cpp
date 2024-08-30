/**
* @file      01_knapsack_2D.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     0/1 Knapsack Problem using 2D DP array.
* https://www.programmercarl.com/%E8%83%8C%E5%8C%85%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%8001%E8%83%8C%E5%8C%85-1.html#%E6%80%9D%E8%B7%AF
* @date      24-8-30
* @copyright Copyright (c) 2024
*/

#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n = 3;
    int bagWeight = 4;  // 样例就和代码随想录上面一致

    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};

    // dp[i][j]表示前i个物品放入容量为j的背包中的最大价值
    vector<vector<int>> dp(n, vector<int>(bagWeight + 1, 0));
    // 这里全部初始化为0 这样第一列就无需初始化了 因为本来dp[i][0]都是0

    // 初始化第一行 能放下第一个物品的背包容量都是第一个物品的价值
    for(int i = 1; i <= bagWeight; i++) {
        if(weight[0] <= i) {
            dp[0][i] = value[0];
        }
    }

    // 先遍历物品再遍历价值 其实2D DP array下遍历顺序无所谓
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= bagWeight; j++) {
            // 如果当前容量j装不下第i个物品 那么最大价值肯定是容量j时 前i-1个物品的最大价值
            if(j < weight[i]) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }

    for(const vector<int>& row : dp) {
        for(const int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}