/**
* @file      total_squares_of_isolated_islands.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     101. 孤岛的总面积
* 给定一个由 1（陆地）和 0（水）组成的矩阵，岛屿指的是由水平或垂直方向上相邻的陆地单元格组成的区域，
* 且完全被水域单元格包围。孤岛是那些位于矩阵内部、所有单元格都不接触边缘的岛屿。
* 现在你需要计算所有孤岛的总面积，岛屿面积的计算方式为组成岛屿的陆地的总数。
* https://www.programmercarl.com/kamacoder/0101.%E5%AD%A4%E5%B2%9B%E7%9A%84%E6%80%BB%E9%9D%A2%E7%A7%AF.html#%E6%80%9D%E8%B7%AF
* @date      24-9-5
* @copyright Copyright (c) 2024
*/


#include <iostream>
#include <vector>

using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
int squares = 0;    // 总面积

/**
 * DFS 返回孤岛总面积，要孤岛其实就是将所有在边界的陆地都标记为0 相当于把边界的岛屿都去掉了
 * 这样最后计算陆地的总面积就是孤岛的总面积
 * @param grid 地图矩阵
 * @param x x axis
 * @param y y axis
 */
void dfs(vector<vector<int>>& grid, int x, int y) {
    grid[x][y] = 0;     // 标记为海洋
    squares++;          // 面积+1
    for(auto & i : dir) {
        int nextX = x + i[0];
        int nextY = y + i[1];
        // 条件判断 越界直接continue
        if(nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()) {
            continue;
        }
        // 是陆地就继续dfs 深搜
        if(grid[nextX][nextY] == 1) {
            dfs(grid, nextX, nextY);
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

    int count = 0;
    for(int i = 0; i < n; i++) {
        // 最左边和最右边
        if(grid[i][0] == 1) {
            dfs(grid, i, 0);
        }
        if(grid[i][m - 1] == 1) {
            dfs(grid, i, m - 1);
        }
    }

    for(int j = 0; j < m; j++) {
        // 最上边和最下边
        if(grid[0][j] == 1) {
            dfs(grid, 0, j);
        }
        if(grid[n - 1][j] == 1) {
            dfs(grid, n - 1, j);
        }
    }
    count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1) {
                count++;
            }
        }
    }
    cout << count << endl;
}

/*
 * 变式——沉没孤岛 跟这道题恰好反过来，开始自己的思路也是添加一个isVisited
 * 但其实按照这个思路将和边界相邻的岛屿都置为2 然后最后循环2->1(边界相邻岛屿) 1->0(孤岛) 就可以了
 */