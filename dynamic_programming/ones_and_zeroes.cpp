/**
* @file      ones_and_zeroes.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC 474.一和零
* https://www.programmercarl.com/0474.%E4%B8%80%E5%92%8C%E9%9B%B6.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-8
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // 用二位dp数组 dp[i][j]表示i个0和j个1最多能组成的字符串数 最大子集大小
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(const string& str : strs) {    // 字符串就是0-1背包中的物品
            int zeros = 0, ones = 0;
            for(char c : str) {
                if (c == '0') {
                    zeros++;
                } else {
                    ones++;
                }
            }
            // 0-1背包问题 逆序遍历 只是两个维度的容量而已 这里的二位其实已经做了降维 不存在物品这个维度了
            for(int i = m; i >= zeros; i--) {
                for(int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }

        return dp[m][n];
    }
};
