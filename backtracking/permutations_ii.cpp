/**
* @file      permutations_ii.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #47.全排列 II
* 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
* https://www.programmercarl.com/0047.%E5%85%A8%E6%8E%92%E5%88%97II.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-1
* @copyright Copyright (c) 2024
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int> nums, vector<bool>& isUsed) {
        // 递归终止条件
        if(nums.size() == path.size()) {
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            // 树层prune 其实对排列来说，树层prune和树枝prune都对，但树层的效率更高，因为树枝prune会有很多错误尝试
            if(i > 0 && nums[i] == nums[i - 1] && !isUsed[i - 1]) {
                continue;
            }
            if(isUsed[i]) { // 防止集合重复 使用过的元素不再使用
                continue;
            }
            path.push_back(nums[i]);
            isUsed[i] = true;
            backtracking(nums, isUsed);
            isUsed[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        path.clear();
        res.clear();
        vector<bool> isUsed(nums.size(), false);
        // 记得树层pruning都要排序，这样才方便判断相邻节点是否已使用
        sort(nums.begin(), nums.end());
        backtracking(nums, isUsed);
        return res;
    }
};

int main() {
    vector<int> nums = {1, 1, 2};
    Solution s;
    vector<vector<int>> res = s.permuteUnique(nums);
    for(auto i : res) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}