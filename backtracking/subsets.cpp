/**
* @file      subsets.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #78.子集
* 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
* 说明：解集不能包含重复的子集。
* 示例: 输入: nums = [1,2,3]
* 输出: [ [3],   [1],   [2],   [1,2,3],   [1,3],   [2,3],   [1,2],   [] ]
* https://www.programmercarl.com/0078.%E5%AD%90%E9%9B%86.html
* @date      24-9-1
* @copyright Copyright (c) 2024
*/


#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;

    void backtracking(int startIdx, vector<int> nums) {
        res.push_back(path);    // 每次都收集当前的path 要在终止之前收集，否则会漏掉本身

        // 递归终止条件 这里寻找子集不是收集叶子节点，而是收集所有节点
        // 所以递归到没有剩余元素可收集时就终止 (其实这个终止条件不加也是OK的，因为for-loop不会再继续了)
        if(path.size() >= nums.size()) {
            return;
        }

        // 子集问题不需要任何pruning 就是要遍历整棵树
        // 用startIdx的内涵是 *无序* 取过不会重复取(集合)
        for(int i = startIdx; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(i + 1, nums);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        path.clear();
        backtracking(0, nums);
        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution s;
    vector<vector<int>> res = s.subsets(nums);
    for(auto& v : res) {
        cout << "[";
        for(auto& i : v) {
            cout << i << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}