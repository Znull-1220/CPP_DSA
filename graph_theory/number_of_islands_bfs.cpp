/**
* @file      number_of_islands_bfs.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC 200 岛屿数量 BFS实现
* https://www.programmercarl.com/kamacoder/0099.%E5%B2%9B%E5%B1%BF%E7%9A%84%E6%95%B0%E9%87%8F%E5%B9%BF%E6%90%9C.html#%E6%80%9D%E8%B7%AF
* @date      24-9-5
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dir[4][2]  = {1, 0, 0, 1, -1, 0, 0, -1};

void bfs(vector<vector<int>>& grid, vector<vector<bool>>& isVisited, int x, int y) {
    queue<pair<int, int>> que;
    que.push({x, y});
    // 特别注意加入队列就立刻标记已访问，而不是出队时再标记，否则会出现重复入队的情况 超时
    isVisited[x][y] = true;
    while(!que.empty()) {
        pair<int, int> axis = que.front();
        que.pop();
        for(int i = 0; i < 4; i++) {
            int nextX = axis.first + dir[i][0];
            int nextY = axis.second + dir[i][1];
            if(nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()) {
                continue;
            }
            if(!isVisited[nextX][nextY] && grid[nextX][nextY] == 1) {
                que.push({nextX, nextY});
                isVisited[nextX][nextY] = true; // 入队就标记已经访问过
            }
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
        for(int j = 0; j < m; j++) {
            if(!isVisited[i][j] && grid[i][j] == 1) {
                count++;    // 岛屿数量+1
                bfs(grid, isVisited, i, j);
            }
        }
    }

    cout << count << endl;
}