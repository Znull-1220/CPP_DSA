/**
* @file      two_sum.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     Leetcode #1.两数之和
* 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
* 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
* 示例:
* 给定 nums = [2, 7, 11, 15], target = 9，因为 nums[0] + nums[1] = 2 + 7 = 9 所以返回 [0, 1]
* @date      24-8-12
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++) {
            // 这里map的key-value key为value即为nums[i]，value为i即为下标 idx
            auto iter = map.find(target - nums[i]);
            if(iter != map.end()) {
                // iter->second 为value即为idx， first为key
                return {iter->second, i};
            }

            map.insert(std::pair<int, int>(nums[i], i));
        }

        return {};
    }
};

int main() {
    std::vector<int> vec = {2, 11, 7, 15};
    int target = 9;

    Solution solution;
    std::vector<int> result = solution.twoSum(vec, target);
    for(int num : result) {
        std::cout << num << " ";
    }
}
