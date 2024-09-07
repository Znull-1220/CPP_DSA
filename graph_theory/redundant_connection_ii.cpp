/**
* @file      redundant_connection_ii.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     109. 冗余连接II (有向图)
* https://www.programmercarl.com/kamacoder/0109.%E5%86%97%E4%BD%99%E8%BF%9E%E6%8E%A5II.html#%E6%80%9D%E8%B7%AF
* @date      24-9-7
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> father(1005);

void init() {
    for(int i = 1; i < father.size(); i++) {
        father[i] = i;
    }
}

int find(int x) {
    return father[x] == x ? x : father[x] = find(father[x]);
}

void join(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if(rx != ry) {
        // 记得是根节点加入，不是x y 不然树的结构就被破坏了
        father[rx] = ry;
    }
}

bool isSame(int x, int y) {
    return find(x) == find(y);
}

/**
 * 判断移除一条边后是否是树
 * @param edges 输入的边
 * @param edgeIdx 要移除的边的序号 (edges[edgeIdx])
 * @return 如果是树返回true，否则返回false
 */
bool isTreeAfterRemove(vector<vector<int>>& edges, int edgeIdx) {
    init();
    for(int i = 0; i < edges.size(); i++) {
        if(i == edgeIdx) {
            continue;
        }
        if(isSame(edges[i][0], edges[i][1])) {
            return false;
        }
        join(edges[i][0], edges[i][1]);
    }
    return true;
}

// 在有向图里找到删除的那条边，使其变成树
void getRemoveEdge(const vector<vector<int>>& edges) {
    init(); // 初始化并查集
    for (int i = 0; i < edges.size(); i++) { // 遍历所有的边
        if (isSame(edges[i][0], edges[i][1])) { // 构成有向环了，就是要删除的边
            cout << edges[i][0] << " " << edges[i][1];
            return;
        } else {
            join(edges[i][0], edges[i][1]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges;
    vector<int> inDegree(n + 1, 0); // 统计节点的入度
    for(int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        edges.push_back({s, t});
        inDegree[t]++;  // target节点的入度+1
    }

    vector<int> vec;    // 记录入度为2的边 这里的边是指的边的序号 就是加入的顺序
    // 从后往前遍历，因为要求返回的是最后加入的边
    for(int i = n - 1; i >= 0; i--) {
        if(inDegree[edges[i][1]] == 2) {
            vec.push_back(i);
        }
    }
    // 如果有入度为2的边，那么就要删除其中一条边，看剩下的图是否有环
    // 情况1. 有入度为2的边，且有环
    // 情况2. 有入度为2的边，且有环，但必须删除特定的一条边，否则有节点会丢失根节点
    if(vec.size() > 0) {
        if(isTreeAfterRemove(edges, vec[0])) {
            cout << edges[vec[0]][0] << " " << edges[vec[0]][1] << endl;
        }
        else {
            // n个节点n条边 最多应该只有一个节点入度为2 那么不是vec[0]就是vec[1] vec[1]删去肯定是第一种情况
            cout << edges[vec[1]][0] << " " << edges[vec[1]][1] << endl;
        }

        return 0;
    }

    // 处理情况三
    // 明确没有入度为2的情况，那么一定有有向环，找到构成环的边返回就可以了
    getRemoveEdge(edges);
}
