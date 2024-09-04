/**
* @file      assign_cookies.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #455. 分发饼干
* 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
* 对每个孩子 i，都有一个胃口值  g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，
* 都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得
* 到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
* @date      24-9-2
* @copyright Copyright (c) 2024
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief 分发饼干
     * @param g 胃口
     * @param s 饼干
     * @return 最大可满足孩子数
     */
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());   // 先排序 小饼干先给胃口小的 贪心策略
        int result = 0;
        int idx = 0;    // 胃口指针
        // 如果从小到大遍历 必须先遍历饼干
        // 反过来是不可以的，因为如果有一个无法满足，那么idx就无法移动，导致无法求解
        // 如果从大到小遍历 那么是先遍历胃口 再遍历饼干 画图看一下就清晰了
        for(int i = 0; i < s.size(); i++) {
            // 用idx来控制而不是用for-loop 注意g本身的边界条件
            /*
             * NOTICE: 当输入s为空时 && 必须先判断idx < s.size()，否则直接访问s[idx] LC会报错
             * 就是出现了越界访问的情况 只要先判断idx < s.size() 逻辑短路掉就OK
             */
            if(idx < g.size() && s[i] >= g[idx]) {
                idx++;
                result++;
            }
        }

        return result;
    }
};

int main() {
    vector<int> g = {1, 2, 3};  // 胃口
    vector<int> s = {1, 1};
    Solution sl;
    cout << sl.findContentChildren(g, s) << endl;
    return 0;
}
