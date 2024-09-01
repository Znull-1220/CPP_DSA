/**
* @file      combination_sum.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     39. 组合总和
* 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
* candidates 中的数字可以无限制重复被选取。
* 说明：所有数字（包括 target）都是正整数; 解集不能包含重复的组合。
* 示例：
* 输入：candidates = [2,3,6,7], target = 7,    所求解集为： [ [7], [2,2,3] ]
* @date      24-9-1
* @copyright Copyright (c) 2024
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;

    /**
     * 回溯
     * @param target 目标和
     * @param sum 当前和 也可以用target- 来代替 这样用sum比较直观一点
     * @param startIdx 组合问题中只要是从同一个集合中选取，都要使用startIdx
     * @param candidates 待选数字
     */
    void backtracking(int target, int sum, int startIdx, vector<int>& candidates) {
        // 终止条件
        if (sum == target) {
            res.push_back(path);
            return;
        }

        // pruning candidates[i] + sum <= target 才处理
        for(int i = startIdx; i < candidates.size() && candidates[i] + sum <= target; i++) {
            path.push_back(candidates[i]); // test 注意这里push_back的是candidates[i]不是i 第一次手误了
            sum += candidates[i];
            // 不用i + 1, 因为可以包含当前i即重复元素
            backtracking(target, sum, i, candidates);
            path.pop_back();    // backtrack
            sum -= candidates[i];
        }

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        path.clear();
        res.clear();
        // 先排序利于剪枝
        sort(candidates.begin(), candidates.end());
        backtracking(target, 0, 0, candidates);
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    vector<vector<int>> res = sol.combinationSum(candidates, 7);
    for(auto vec : res) {
        for(auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}