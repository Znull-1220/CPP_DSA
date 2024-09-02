/**
* @file      non_decreasing_subsequences.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #491.递增子序列
* 给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2
* 示例:
* 输入: [4, 6, 7, 7]
* 输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
* 说明:
* 给定数组的长度不会超过15; 数组中的整数范围是 [-100,100]
* 给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况
* https://www.programmercarl.com/0491.%E9%80%92%E5%A2%9E%E5%AD%90%E5%BA%8F%E5%88%97.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-1
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;

    void backtracking(int startIdx, vector<int>& nums) {
        // 节点收集 注意因为要求长度至少为2 所以这里要判断path的长度
        if(path.size() > 1) {
            res.push_back(path);    // 不return, 要取树所有节点
        }
        unordered_set<int> uset;    // 用来去重
        // 更好的方法是用数组 时间复杂度底
        //int isUsed[201] = {0};

        // 终止条件在for循环里面
        for(int i = startIdx; i < nums.size(); i++) {
            // 这里是树层去重 以及确保递增 非空时候考察递增才有意义 此时才可以比较元素
            if(!path.empty() && nums[i] < path.back() || uset.find(nums[i]) != uset.end()) {
                continue;
            }
            uset.insert(nums[i]);   // 加入到uset里面 为当前层去重
            path.push_back(nums[i]);
            backtracking(i + 1, nums);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(0, nums);
        return res;
    }
};

int main() {
    vector<int> nums = {4, 6, 7, 7};
    Solution s;
    vector<vector<int>> res = s.findSubsequences(nums);
    for(auto i : res) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}