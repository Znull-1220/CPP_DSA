/**
* @file      redundant_connection.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     108. 冗余连接
* https://www.programmercarl.com/kamacoder/0108.%E5%86%97%E4%BD%99%E8%BF%9E%E6%8E%A5.html#%E6%80%9D%E8%B7%AF
* https://leetcode.cn/problems/redundant-connection/description/
* @date      24-9-7
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> father(1005);

/*
 * 思路就是构造并查集，如果两个节点已经在一个集合中了，那么再连起来就会形成环
 */
class UnionFind {
public:
    static void init() {
        for(int i = 1; i < father.size(); i++) {
            father[i] = i;
        }
    }

    static int find(int x) {
        return father[x] == x ? x : father[x] = find(father[x]);
    }

    static void join(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if(rx != ry) {
            father[rx] = ry;
        }
        // 在一个集合中的话，不需要操作
    }

    static bool isSameSet(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    int n;
    cin >> n;
    UnionFind::init();
    for(int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        // 要求输出标准输入的最后一条边，那么直接按顺序构成并查集，这样最后一条输入的就直接查到出现环了
        if(UnionFind::find(s) == UnionFind::find(t)) {
            cout << s << " " << t << endl;
            return 0;
        }
        else {
            UnionFind::join(s, t);
        }
    }

    return 0;
}