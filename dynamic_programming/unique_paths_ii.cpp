/**
* @file      unique_paths_ii.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #63. 不同路径 II
* 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）
* 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）
* 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
* 网格中的障碍物和空位置分别用 1 和 0 来表示
* 输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]   输出：2
* 解释：
* 3x3 网格的正中间有一个障碍物。
* 从左上角到右下角一共有 2 条不同的路径：
* 向右 -> 向右 -> 向下 -> 向下;         向下 -> 向下 -> 向右 -> 向右
* https://www.programmercarl.com/0063.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84II.html
* @date      24-8-25
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();    // 行数
        int n = obstacleGrid[0].size(); // 列数 [0] 为二维数组的第一行

        // 如果在起点或终点出现了障碍，直接返回0
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }

        vector<vector<int>> dp(m, vector<int>(n, 0)); // 初始化二维数组

        // 初始化第一行
        for(int i = 0; i < m; i++) {
            // 第一行 遇到obstacleGrid[i][0] == 1时，后面的都不可达
            if(obstacleGrid[i][0] == 1) {
                break;
            }
            dp[i][0] = 1;
        }
        for(int j = 0; j < n; j++) {
            if(obstacleGrid[0][j] == 1) {
                break;
            }
            dp[0][j] = 1;
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                // 有障碍物的地方不可达 0 直接跳过
                if(obstacleGrid[i][j] == 1) {
                    continue;
                }

                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};


int main() {
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution sol;
    int result = sol.uniquePathsWithObstacles(obstacleGrid);
    cout << result << endl;

    // 错误退出代码-1073741819(0xC0000005) Segment fault 查循环边界条件 vec越界了!
}
