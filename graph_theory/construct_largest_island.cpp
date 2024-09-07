/**
* @file      construct_largest_island.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     104. 建造最大岛屿
* 给定一个由 1（陆地）和 0（水）组成的矩阵，你最多可以将矩阵中的一格水变为一块陆地，
* 在执行了此操作之后，矩阵中最大的岛屿面积是多少。
* 岛屿面积的计算方式为组成岛屿的陆地的总数。岛屿是被水包围，并且通过水平方向或垂直方
* 向上相邻的陆地连接而成的。你可以假设矩阵外均被水包围。
* https://www.programmercarl.com/kamacoder/0104.%E5%BB%BA%E9%80%A0%E6%9C%80%E5%A4%A7%E5%B2%9B%E5%B1%BF.html#%E6%80%9D%E8%B7%AF
* @date      24-9-5
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/**
 * 最直白的暴力思路，遍历每一个水格子，将其变为陆地，然后深度优先搜索，找到最大的岛屿面积
 * 这样O(n^4)的复杂度，肯定会超时
 * 可以引入一个编号，先深搜为每个岛屿的格子 1->各自的编号
 * 然后遍历每个格子 找到周围的岛屿面积 加起来即可
 */

int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
unordered_map<int, int> islandArea; // 岛屿编号->面积

void dfs(vector<vector<int>>& grid, int x, int y, int mark) {
    if(grid[x][y] == 0 ||  grid[x][y] != 1) {   // dfs进入的判断其实涵盖在这里了
        return;
    }
    grid[x][y] = mark;  // 先标记 不然第一个点没有处理
    islandArea[mark]++;
    // 标记为mark其实也就不需要isVisited数组了 因为其它节点被置为mark后 不满足=1就不会再访问了

    for(int i = 0; i < 4; i++) {
        int nextX = x + dirs[i][0];
        int nextY = y + dirs[i][1];
        if(nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()) {
            continue;
        }

        dfs(grid, nextX, nextY, mark);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int mark = 2;   // 从2开始编号 1是陆地
    bool isAllIsland = true;    // 标记是否全是岛屿
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 0)
                isAllIsland = false;
            if(grid[i][j] == 1) {
                dfs(grid, i, j, mark);
                mark++;
            }
        }
    }

    if(isAllIsland) {
        cout << n * m << endl;
        return 0;
    }

    int result = 0; // 最大岛屿面积结果
    unordered_set<int> visited; // 记录已经访问过的岛屿编号
    int count = 1;  // 记录周围岛屿的面积 起始是1因为可以插入一个陆地

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 0) {   // 遍历每一个水格子 必须是海才能放置陆地
                visited.clear();
                for(auto & dir : dirs) {
                    int nextX = i + dir[0];
                    int nextY = j + dir[1];
                    if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) {
                        continue;
                    }
                    // 第一次这里忘记判断非法和去重了... 结果特别大
                    if(grid[nextX][nextY] != 0 && visited.find(grid[nextX][nextY]) == visited.end()) {
                        count += islandArea[grid[nextX][nextY]];
                        visited.insert(grid[nextX][nextY]);
                    }
                }
                result = max(result, count);
                count = 1;
            }
        }
    }

    cout << result << endl;
    return 0;
}
