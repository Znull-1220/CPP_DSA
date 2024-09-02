/**
* @file      reconstruct_itinerary.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #332.重新安排行程 hard
* 给定一个机票的字符串二维数组 [from, to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，
* 对该行程进行重新规划排序。所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。
* 提示：
* 如果存在多种有效的行程，请你按字符自然排序返回最小的行程组合。
* 例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前
* 所有的机场都用三个大写字母表示（机场代码）。
* 假定所有机票至少存在一种合理的行程; 所有的机票必须都用一次 且 只能用一次。
* 示例 1：
* 输入：[["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
* 输出：["JFK", "MUC", "LHR", "SFO", "SJC"]
* https://www.programmercarl.com/0332.%E9%87%8D%E6%96%B0%E5%AE%89%E6%8E%92%E8%A1%8C%E7%A8%8B.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-2
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <map>  // 因为要求按照字母排序，所以用map 排序Key
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    // unordered_map<出发机场, map<到达机场, 航班次数>> targets
    unordered_map<string, map<string, int>> targets;
    /*
     * unordered_map<string, multiset<string>> targets 也是一种思路
     * 但删除set中的元素会导致迭代器失效
     */
    vector<string> res;

    /**
     * Backtrack 因为我们只需要找到一个行程，就是在树形结构中唯一的一条通向叶子节点的路线 所以返回bool即可
     * @param flightNum 已经飞过的航班次数
     * @return Bool值 表示是否找到该唯一路径
     */
    bool backtracking(int ticketNum) {
        // 终止条件 当res的长度等于航班数+1时，表示找到了一条路径 就是所有的航班都飞过了
        if (res.size() == ticketNum + 1) {
            return true;
        }

        /*
         * NOTICE:
         * 1. 这里必须用引用&，这样才能修改nested map中的value保证不会重复
         * 如果不用引用那么复制新的对会导致重复
         * 2. 对string加const的原因是，map里面的key是const不可修改(红黑树)，它默认就是const key
         * 如果不加const那么类型是不匹配的
         * 报pair<string, int>& 非const左值应用无法绑定到 pair<const string, int>不匹配
         */
        // targets[res[res.size() - 1]] 表示当前机场的所有目的地 在该机场的目的地中遍历
        for (pair<const string, int>& target : targets[res[res.size() - 1]]) {
            // 当前机场到该目的地的航班次数大于0时，才能飞
            if(target.second > 0) {
                res.push_back(target.first);
                target.second--;    // 航班次数减1
                if(backtracking(ticketNum)) {
                    return true;
                }
                // 回溯
                res.pop_back();
                target.second++;
            }
        }

        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        res.clear();
        targets.clear();
        for(auto& ticket :tickets) {
            targets[ticket[0]][ticket[1]]++;    // 用map来存储航班次数 nested map用两个[]来访问就OK了
        }
        res.push_back("JFK");   // 起始机场push进去
        backtracking(tickets.size());
        return res;
    }
};

int main() {
    vector<vector<string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    Solution s;
    vector<string> res = s.findItinerary(tickets);
    for(auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}