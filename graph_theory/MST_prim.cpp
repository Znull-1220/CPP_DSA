/**
* @file      MST_prim.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     最小生成树 prim算法
* https://www.programmercarl.com/kamacoder/0053.%E5%AF%BB%E5%AE%9D-prim.html#%E8%A7%A3%E9%A2%98%E6%80%9D%E8%B7%AF
* @date      24-9-8
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int v, e;
    cin >> v >> e;
    // 用邻接矩阵存 因为是带权无向图 所以初始化为无穷大 表示不联通
    vector<vector<int>> graph(v + 1, vector<int>(v + 1, INT_MAX));
    while(e--) {
        int s, t, k;    // k是边的权重
        cin >> s >> t >> k;
        graph[s][t] = k;
        graph[t][s] = k;    // 无向图 这里双向存储
    }

    // 这个是算法的核心部分 表示 *未在生成树中的点* 到 *生成树各节点* 的最短距离
    // 最大权值是10000 所以初始化为10001 这样才能让第一个点加入生成树
    vector<int> minDist(v + 1, 10001); // 从1开始编号
    vector<bool> isInTree(v + 1, false); // 标记是否在生成树中
    // 标记路径的时候 需要用到的数组
    vector<int> parent(v + 1, -1);

    // v个节点 最小生成树有v-1条边 循环v-1次
    for (int i = 1; i < v; i++) {
        int cur = -1;
        int minVal = INT_MAX;
        // 节点1-v 1. 选出距离生成树最近的点
        for(int j = 1; j <= v; j++) {
            // 加入条件 点不在生成树中 并且 距离生成树的距离最小
            if (!isInTree[j] && minDist[j] < minVal) {
                cur = j;
                minVal = minDist[j];
            }
        }

        // 2. 最近节点加入生成树
        isInTree[cur] = true;

        // 3. 更新minDist 因为只是当前节点加入了生成树 所以只需要更新与当前节点相连的点
        for(int k = 1; k <= v; k++) {
            // 加入条件 点不在生成树中 并且 距离生成树的距离比之前的小
            if(!isInTree[k] && graph[cur][k] < minDist[k]) {
                minDist[k] = graph[cur][k];
                // 记录当前节点的父节点 为cur
                // 注意不能颠倒！！！
                // 因为如果cur到多个节点的距离都比之前更小的话 就只会记录最后一个 出现错误
                parent[k] = cur;
            }
        }
    }

    int result = 0;
    // 从第二个节点开始加入 第一个点的权值不计了 因为本来就没父节点 统计节点2-v
    for(int i = 2; i <= v; i++) {
        result += minDist[i];
    }

    cout << result << endl;
}
