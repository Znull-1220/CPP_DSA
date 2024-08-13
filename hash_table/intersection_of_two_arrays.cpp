/**
* @file      intersection_of_two_arrays.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     Leetcode #349. 两个数组的交集 题意：给定两个数组，计算它们的交集。
* https://leetcode.cn/problems/intersection-of-two-arrays/description/
* @date      24-8-12
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        // unorder_set 使用hash表实现，读写效率最高
        // 要求无重复-> 用set;    可以无序-> 用unordered_set
        std::unordered_set<int> result;
        std::unordered_set<int> nums1_set(nums1.begin(), nums1.end());  // 去重nums1
        for(int num : nums2) {
            if(nums1_set.find(num) != nums1_set.end()) {
                result.insert(num);
            }
        }

        return std::vector<int>(result.begin(), result.end());
    }
};

int main() {
    std::vector<int> nums1 = {1, 2, 2, 1, 5};
    std::vector<int> nums2 = {2, 2, 3, 4, 5};
    Solution solution;
    std::vector<int> result = solution.intersection(nums1, nums2);
    for(int num : result) {
        std::cout << num << " ";
    }
}
