/**
* @file      all_paths_from_source_to_target.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     所有可达路径 DFS模板题 有向无环图
* https://kamacoder.com/problempage.php?pid=1170
* https://www.programmercarl.com/kamacoder/0098.%E6%89%80%E6%9C%89%E5%8F%AF%E8%BE%BE%E8%B7%AF%E5%BE%84.html#%E6%8F%92%E6%9B%B2
* @date      24-9-4
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <list> // 链表 邻接表存储会用到

using namespace std;

vector<vector<int>> res;
vector<int> path;

// 邻接矩阵存储图
void dfs1(vector<vector<int>>& graph, int cur, int dest) {
    // 递归终止条件
    if(cur == dest) {
        res.push_back(path);
        return;
    }
    for(int i = 1; i < graph.size(); i++) {
        // cur -> i 的一条路径如果存在 这道题是有向无环图
        // i = 1开始是保持节点编号与下标一致 邻接表/邻接矩阵都开的是n+1的空间
        if(graph[cur][i] == 1) {
            path.push_back(i);
            dfs1(graph, i, dest);
            path.pop_back();
        }
    }
}


// 邻接表存储图
// vector<list<int>>& graph
void dfs2(vector<list<int>>& graph, int cur, int dest) {
    // 递归终止条件
    if(cur == dest) {
        res.push_back(path);
        return;
    }
    for(auto& i : graph[cur]) {
        path.push_back(i);
        dfs2(graph, i, dest);
        path.pop_back();
    }
}

int main() {
    int n, m;   // n个节点 m条边
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    int s, t;   // source target
    for(int i = 0; i < m; i++) {
        cin >> s >> t;
        graph[s][t] = 1;
    }
    path.push_back(1);  // 起始节点 从1出发
    dfs1(graph, 1, n);
    // 如果不存在任何一条路径，则输出 -1 开始忘记了这种情况导致一个点WA
    if(res.size() == 0) {
        cout << -1 <<endl;
        return 0;
    }
    for(auto& p : res) {
        for(int i = 0; i < p.size() - 1; i++) {
            cout << p[i] << " ";    // 最后一个不输出空格
        }
        cout << p[p.size() - 1] << endl;
    }
}