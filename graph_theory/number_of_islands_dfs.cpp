/**
* @file      number_of_islands_dfs.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC 200 岛屿数量 DFS实现
* https://www.programmercarl.com/kamacoder/0099.%E5%B2%9B%E5%B1%BF%E7%9A%84%E6%95%B0%E9%87%8F%E6%B7%B1%E6%90%9C.html#%E6%80%9D%E8%B7%AF
* @date      24-9-5
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

/**
 * DFS
 * @param grid 地图矩阵
 * @param isVisited 标记是否访问过
 * @param x x axis
 * @param y y axis
 */
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& isVisited, int x, int y) {
    // 终止条件 这个看写法 可以不用
    // 访问过/遇到海水
    if(isVisited[x][y] || grid[x][y] == 0) {
        // 第一次不小心写成'0' 了 答案不对 这样可能把周围的1都标记成访问过了 但没有记录...
        return;
    }
    isVisited[x][y] = true;
    // 有四个方向
    for(int i = 0; i < 4; i++) {
        int nextX = x + dir[i][0];
        int nextY = y + dir[i][1];
        // 条件判断 越界直接continue
        if(nextX >= grid.size() || nextX < 0 || nextY >= grid[0].size() || nextY < 0) {
            continue;
        }
        dfs(grid, isVisited, nextX, nextY);
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

    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!isVisited[i][j] && grid[i][j] == 1) {
                count++;    // 岛屿数量+1
                dfs(grid, isVisited, i, j);
            }
        }
    }

    cout << count << endl;
}