/**
* @file      combination_sum_ii.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #40.组合总和II
* 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
* candidates 中的每个数字在每个组合中只能使用一次。
* 说明： 所有数字（包括目标数）都是正整数。解集不能包含重复的组合。
* https://www.programmercarl.com/0040.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CII.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-1
* @copyright Copyright (c) 2024
*/

// 与combination_sum的区别是每个数字在每个组合中只能使用一次
// 集合（数组candidates）有重复元素，但还不能有重复的组合

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;

    void backtracking(int target, int sum, int startIdx, vector<bool>& isUsed, vector<int>& candidates) {
        // 终止条件
        if(sum == target) {
            res.push_back(path);
            return;
        }

        for(int i = startIdx; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // isUsed[i - 1] == true 说明同一树支candidates[i - 1]使用过
            // isUsed[i - 1] == false 说明同一树层candidates[i - 1]使用过
            // 题目要求的是无重复集合，就是同一树层不能重复
            // 如果后面相同的第一个元素重复 那么后面的子集有重复的话确实有可能出现重复组合
            // 因为集合本来就有重复元素，所以同一树支是可重复的
            // 总结来说就是回溯不能重复，但递归的树支可以重复
            if(i > 0 && candidates[i] == candidates[i - 1] && !isUsed[i - 1]) {  // 去树层重复
                // 一定注意边界条件i > 0 细节 否则出现数组越界 LC上报overflow
                continue;
            }

            /*
             * 要对同一树层使用过的元素进行跳过 用startIdx去重也OK.
               if (i > startIndex && candidates[i] == candidates[i - 1]) {
                   continue;
               }
             */

            path.push_back(candidates[i]);
            sum += candidates[i];
            isUsed[i] = true;
            backtracking(target, sum, i + 1, isUsed, candidates);
            // backtrack
            path.pop_back();
            sum -= candidates[i];
            isUsed[i] = false;  // 因为这里有对isUsed的回溯 所以函数引用传递isUsed也可以
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        path.clear();
        res.clear();
        vector<bool> isUsed(candidates.size(), false);
        // sort 让相同元素挨在一起 这样之前的分析才是合理的
        sort(candidates.begin(), candidates.end());
        backtracking(target, 0, 0, isUsed, candidates);

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> res = sol.combinationSum2(candidates, 8);
    for(auto vec : res) {
        for(auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}