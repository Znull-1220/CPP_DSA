# graph theory
## basic concept
1. 分类：有向图，无向图
2. 节点的度：入度，出度
3. 连通性
   - 无向图：连通图，非连通图
   - 有向图：强连通（有向图中任何两个节点是可以相互到达），弱连通
4. 连通分量
    - 无向图：极大连通子图称为连通分量
    - 有向图：极大强连通分量（极大强连通子图），没有极小强连通分量这个概念
5. 存储方式
    - 邻接矩阵：适合稠密图
    - 邻接表：适合稀疏图 检查两个节点之间是否存在边的时间复杂度为O(n)
6. 遍历
    - 深度优先搜索DFS
    - 广度优先搜索BFS
## 图的遍历
### DFS
类似树的递归遍历 递归 -> 回溯；回溯算法其实就是DFS的过程

### BFS
板子
```c++
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 表示四个方向
// grid 是地图，也就是一个二维数组
// visited标记访问过的节点，不要重复访问
// x,y 表示开始搜索节点的下标
void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
    queue<pair<int, int>> que; // 定义队列
    que.push({x, y}); // 起始节点加入队列
    visited[x][y] = true; // 只要加入队列，立刻标记为访问过的节点
    while(!que.empty()) { // 开始遍历队列里的元素
        pair<int ,int> cur = que.front(); que.pop(); // 从队列取元素
        int curx = cur.first;
        int cury = cur.second; // 当前节点坐标
        for (int i = 0; i < 4; i++) { // 开始想当前节点的四个方向左右上下去遍历
            int nextx = curx + dir[i][0];
            int nexty = cury + dir[i][1]; // 获取周边四个方向的坐标
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;  // 坐标越界了，直接跳过
            if (!visited[nextx][nexty]) { // 如果节点没被访问过
                que.push({nextx, nexty});  // 队列添加该节点为下一轮要遍历的节点
                visited[nextx][nexty] = true; // 只要加入队列立刻标记，避免重复访问
            }
        }
    }

}
```
因为BFS是一层一层的遍历，当遍历到终点时，一定是最短路径