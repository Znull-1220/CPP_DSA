/**
* @file      find_a_existing_path.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     107. 寻找存在的路径
* 题目描述
* 给定一个包含 n 个节点的无向图中，节点编号从 1 到 n （含 1 和 n ）。
* 你的任务是判断是否有一条从节点 source 出发到节点 destination 的路径存在。
* 输入描述
* 第一行包含两个正整数 N 和 M，N 代表节点的个数，M 代表边的个数。
* 后续 M 行，每行两个正整数 s 和 t，代表从节点 s 与节点 t 之间有一条边。
* 最后一行包含两个正整数，代表起始节点 source 和目标节点 destination。
* 输出描述
* 输出一个整数，代表是否存在从节点 source 到节点 destination 的路径。如果存在，输出 1；否则，输出 0。
* https://www.programmercarl.com/kamacoder/0107.%E5%AF%BB%E6%89%BE%E5%AD%98%E5%9C%A8%E7%9A%84%E8%B7%AF%E5%BE%84.html#%E6%80%9D%E8%B7%AF
 * @date      24-9-7
 * @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;
// 按测试数据开全局变量了 稍微大一点 这里也用1-based
vector<int> father(105);
/*
 * 分析：典型的并查集问题，找到两个节点是否在同一个集合中->是否有路径
 */
class UnionFind {
public:
    void init() {
        // 初始化每个节点的父节点为自己
        for(int i = 1; i < father.size(); i++) {
            father[i] = i;
        }
    }

    int find(int x) {
        if(father[x] == x)
            return x;

        return father[x] = find(father[x]); // 路径压缩 注意这里是father[x] 不是x 递归找到根节点
    }

    void join(int a, int b) {
        int fa = find(a);
        int fb = find(b);
        if(fa != fb) {
            // 将a的父节点指向b的父节点
            father[fa] = fb;
        }
    }

    bool isSame(int a, int b) {
        return find(a) == find(b);
    }
};


int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf;
    uf.init();  // 开始忘记初始化并查集了..
    for(int i = 0; i < m; i++) {
        int s, t;
        cin >> s >> t;
        uf.join(s, t);  // 合并两个节点 集合
    }
    int s, t;
    cin >> s >> t;
    if(uf.isSame(s, t)) {
        cout << 1 << endl;
    }
    else {
        cout << 0 <<endl;
    }

    return 0;
}