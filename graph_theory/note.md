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

## 并查集
并查集 Union-Find Set 这一数据结构用于处理一些不交集的合并及查询问题。主要用于
- 将两个元素添加到一个集合中     ```join(u, v)```
- 查询两个元素是否在同一个集合中  ```isSame(u, v)```

还包括求联通子图，最小生成树Kruskal算法等问题

**大白话就是当我们需要判断两个元素是否在同一个集合里的时候，我们就要想到用并查集。**

### 并查集的基本操作
#### 初始化
需要用到father数组表征每个节点的父节点 初始化时，每个节点的父节点都是它自己
```c++
void init() {
    for (int i = 0; i < n; ++i) {
        father[i] = i;
    }
}
```
#### 查找根节点
```c++
int find(int u) {
    if (u == father[u]) return u; // 如果根就是自己，直接返回
    else return find(father[u]); // 如果根不是自己，就根据数组下标一层一层向下找
}
```
终止条件 找到根节点 根据初始化的设定那么根节点的父节点就是它自己
#### 合并
```c++
// 将v，u 这条边加入并查集
void join(int u, int v) {
    u = find(u); // 寻找u的根
    v = find(v); // 寻找v的根
    if (u == v) return; // 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回
    father[v] = u;
}
```
这种数据结构是有向图，father[v] = u 那么 v -> u，但是不需要双向联通，查找在一个集合中，知道有单向联通已经足够了
#### 判断是否在同一个集合
```c++
// 判断 u 和 v是否找到同一个根
bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}
```
简单直白。
### 路径压缩
按照上面的方法，每次find的时候都要递归的向上找，这样效率很低，所以我们可以在find的时候，将路径上的所有节点都指向根节点，这样下次再find的时候就会很快。

就是构造一棵多叉树，每个节点的父节点都是根节点，这样就可以保证每次find的时间复杂度是O(1)
```c++
// 并查集里寻根的过程
int find(int u) {
    if (u == father[u]) return u;
    else return father[u] = find(father[u]); // 路径压缩
}
```
或者用三元表达式
```c++
int find(int u) {
    return u == father[u] ? u : father[u] = find(father[u]);
}
```
### 按秩合并
这里的rank指的是树的高度，我们在合并的时候，可以将高度较小的树合并到高度较大的树上，这样可以减少树的高度，提高效率

但是通常用路径压缩就够了，因为路径压缩的效果更好，而且实现起来更简单；同时使用的话收益会很小。