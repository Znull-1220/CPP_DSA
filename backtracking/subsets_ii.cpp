/**
* @file      subsets_ii.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #90.子集II
* 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
* 说明：解集不能包含重复的子集。
* https://www.programmercarl.com/0090.%E5%AD%90%E9%9B%86II.html#%E6%80%9D%E8%B7%AF
* @date      24-9-1
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 这道题和之前LC #40.组合总和II的去重思路一样 树层去重，而树枝可重复
class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(int startIdx, vector<int>& nums) {
        // 收集各节点
        res.push_back(path);
        // 和刚才一样，没必要写终止条件，for循环里面的条件已经包含了 会自己终止
        for(int i = startIdx; i < nums.size(); i++) {
            // 这里isUsed来标记了 直接用startIdx简单点 也就是第一个遍历过了，后面的相同元素树枝直接剪掉就可以了
            // 还有一种思路是用set去重，但是这样会增加空间复杂度 就是每层只能遍历一个相同的元素
            if(i > startIdx && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            backtracking(i + 1, nums);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtracking(0, nums);
        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 2};
    Solution s;
    vector<vector<int>> res = s.subsetsWithDup(nums);
    for(auto i : res) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}