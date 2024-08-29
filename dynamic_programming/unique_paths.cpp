/**
* @file      unique_paths.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #62. 不同路径 Unique Paths
* 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start”）
* 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）
* 问总共有多少条不同的路径
* 示例 ：
* 输入：m = 3, n = 2   输出：3
* 解释：
* 从左上角开始，总共有 3 条路径可以到达右下角。
* 1. 向右 -> 向下 -> 向下
* 2. 向下 -> 向下 -> 向右
* 3. 向下 -> 向右 -> 向下
* @date      24-8-24
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 初始化边界条件 dp[i][0] = dp[0][j] = 1两个边界都是只有一种走法
        for(int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for(int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1]; // 两个方向走过来
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution s;
    cout << s.uniquePaths(7, 3) << endl;
    return 0;
}