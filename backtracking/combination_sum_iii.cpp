/**
* @file      combination_sum_iii.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC 216.组合总和III
* 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
* 说明：
* 所有数字都是正整数。
* 解集不能包含重复的组合。
* 示例 1: 输入: k = 3, n = 7 输出: [[1,2,4]]
* 示例 2: 输入: k = 3, n = 9 输出: [[1,2,6], [1,3,5], [2,3,4]]
* @date      24-9-1
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;

    /**
     * backtracking
     * @param k 组合数数目
     * @param targetSum 目标和
     * @param sum 当前和 即path中元素之和
     * @param startIdx 下一层for循环搜索的起始位置
     */
    void backtracking(int k, int targetSum, int sum, int startIdx) {
        // pruning 当path的元素和大于targetSum时，就不用再往下搜索了
        if(sum > targetSum) {   // 放在回溯开始 这个pruning放在for-loop里面也是OK的.
            return;
        }

        // 终止条件
        if(path.size() == k && sum == targetSum) {
            res.push_back(path);
            return;
        }

        // 和基础的组合元素pruning一样 另一个额外约束条件就是当path的元素sum大于targetSum时，就不用再往下搜索了
        for(int i = startIdx; i <= 9 - (k - path.size()) + 1; i++) {
            path.push_back(i);  // 将当前元素添加到路径 尝试当前路径
            sum += i;
            backtracking(k, targetSum, sum, i + 1); // 注意调整startIdx为i + 1 保证不重复
            path.pop_back();  // 回溯 退回上一个节点
            sum -= i;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        path.clear();
        res.clear();
        backtracking(k, n, 0, 1);
        return res;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> res = sol.combinationSum3(3, 9);
    for(auto vec : res) {
        for(auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}