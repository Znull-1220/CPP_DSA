/**
* @file      waterflow_problem.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     103. 水流问题
* https://www.programmercarl.com/kamacoder/0103.%E6%B0%B4%E6%B5%81%E9%97%AE%E9%A2%98.html#%E6%80%9D%E8%B7%AF
* @date      24-9-5
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
/**
 * 正向思路的时间复杂度会较高 就是看各点是否能走到两个边界
 * 可以考虑采用逆向思路 从两个边界开始dfs，最后两个边界都能走到的点就是答案
 */
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& isVisited, int x, int y) {
    isVisited[x][y] = true;    // 标记已经访问过 应该必须写在这里 否则会漏掉初始点

    for(int i = 0; i < 4; i++) {
        int nextX = x + dir[i][0];
        int nextY = y + dir[i][1];
        if(nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size())
            continue;
        if(grid[x][y] > grid[nextX][nextY])     // 逆向思路 不能比周围的点高
            continue;
        if(!isVisited[nextX][nextY]) {
            dfs(grid, isVisited, nextX, nextY);
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> firstBorder(n, vector<bool>(m, false));
    vector<vector<bool>> secondBorder(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++) {
        dfs(grid, firstBorder, i, 0);
        dfs(grid, secondBorder, i, m - 1);
    }

    for(int j = 0; j < m; j++) {
        dfs(grid, firstBorder, 0, j);
        dfs(grid, secondBorder, n - 1, j);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(firstBorder[i][j] && secondBorder[i][j]) {
                cout << i << ' ' << j << endl;
            }
        }
    }
}