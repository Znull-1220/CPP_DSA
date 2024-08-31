/**
* @file      combinations.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #77.组合
* 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
* 你可以按 任何顺序 返回答案。
* https://www.programmercarl.com/0077.%E7%BB%84%E5%90%88.html#%E6%80%9D%E8%B7%AF
* @date      24-8-31
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;

    void backtracking(int n, int k, int startIndex) {
        // 终止条件
        if(path.size() == k) {
            res.push_back(path);
            return;
        }

        // NOTICE i should equal startIndex 否则变为一个排列
        // for(int i = startIndex; i <= n; i++) {
        // pruning 当for循环选择的起始位置之后的元素个数已经不足我们需要的元素个数了，那么就没有必要搜索了
        // 例如 n=4 k=3 当path.size == 0时，n - (k - path.size()) + 1 = 2 从2开始[2 3 4]是合理的
        for(int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);  // 将当前元素添加到路径 尝试当前路径
            backtracking(n, k, i + 1);  // 递归
            path.pop_back();  // 回溯 退回上一个节点
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        path.clear();
        res.clear();
        backtracking(n, k, 1);
        return res;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> res = sol.combine(4, 2);
    for(auto vec : res) {
        for(auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
