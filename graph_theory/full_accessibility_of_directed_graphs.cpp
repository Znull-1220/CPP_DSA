/**
* @file      full_accessibility_of_directed_graphs.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     KamaCoder 105. 有向图的完全可达性
* 题目描述
* 给定一个有向图，包含 N 个节点，节点编号分别为 1，2，...，N。现从 1 号节点开始，如果可以从 1 号节点的边可以
* 到达任何节点，则输出 1，否则输出 -1。
* 输入描述
* 第一行包含两个正整数，表示节点数量 N 和边的数量 K。 后续 K 行，每行两个正整数 s 和 t，表示从 s 节点有一条
* 边单向连接到 t 节点。
* 输出描述
* 如果可以从 1 号节点的边可以到达任何节点，则输出 1，否则输出 -1。
* @date      24-9-7
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

// DFS/BFS都可以
void dfs(vector<list<int>>& graph, int key, vector<bool>& isVisited) {
    if(isVisited[key])
        return;
    isVisited[key] = true;  // 这种思路是处理当前访问的节点
    // 也可以处理下一个节点 那么逻辑需要稍微变一下
    list<int> adjList = graph[key];
    for(auto& adj : adjList) {
        dfs(graph, adj, isVisited);
    }
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<list<int>> graph(n + 1);    // 1-based 邻接表
    for(int i = 0; i < k; i++) {
        int s, t;
        cin >> s >> t;
        graph[s].push_back(t);
    }

    vector<bool> isVisited(n + 1, false);
    dfs(graph, 1, isVisited);

    for(int i = 1; i <= n; i++) {
        if(isVisited[i] == false) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << 1 << endl;
    return 0;
}