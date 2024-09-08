/**
* @file      MST_kruskal.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     最小生成树 kruskal算法
* @date      24-9-8
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int s, t, val;
};

vector<int> father(10001);  // 最大点数为10000

void init() {
    for (int i = 0; i < father.size(); i++) {
        father[i] = i;
    }
}

int find(int x) {
    return father[x] == x ? x : father[x] = find(father[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        father[x] = y;
    }
}

bool isSame(int x, int y) {
    return find(x) == find(y);
}

int main() {
    vector<Edge> edges;
    int v, e;
    cin >> v >> e;
    while (e--) {
        int s, t, k;
        cin >> s >> t >> k;
        edges.push_back({s, t, k});
    }

    // 从小到大排序
    // lambda表达式 [捕获列表](参数列表){} —> type
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.val < b.val;
    });

    int res = 0;    // 最小生成树的权值和
    init();
    // 如果要存储最小生成树的边，可以在这里定义一个vector<Edge> resEdges
    vector<Edge> result;
    for(auto & edge : edges) {
        if(isSame(edge.s, edge.t)) {
            continue;
        }
        join(edge.s, edge.t);
        res += edge.val;
        // result.push_back(edge);
    }

    cout << res << endl;
    return 0;
}