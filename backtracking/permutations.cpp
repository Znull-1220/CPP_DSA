/**
* @file      permutations.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #46.全排列
* 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案
* https://www.programmercarl.com/0046.%E5%85%A8%E6%8E%92%E5%88%97.html#%E6%80%9D%E8%B7%AF
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
    vector<bool> used;
    void backtracking(vector<int>& nums) {
        // 递归终止条件 和nums长度相等就是一个全排列
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            // 如果用过就跳出本次循环  因为一个全排列中不能重复之前path中用过的元素
            // 相当于保证全排列中的元素不重复
            if(used[i] == true) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        path.clear();
        used = vector<bool>(nums.size(), false);
        backtracking(nums);
        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution s;
    vector<vector<int>> res = s.permute(nums);
    for(auto& r : res) {
        for(auto& i : r) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
