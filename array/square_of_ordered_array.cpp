/**
* @file      square_of_ordered_array.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     Leetcode977 有序数组的平方 ref: https://leetcode.cn/problems/squares-of-a-sorted-array/
* 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
* 示例 1：
* 输入：nums = [-4,-1,0,3,10]
* 输出：[0,1,9,16,100]
* @date      24-8-2
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>


class Solution {
public:
    /**
     * 双指针解法. while循环 很直观 O(n)
     * @param nums 输入的有序数组
     * @return 每个数字的平方组成的新数组
     */
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        std::vector<int> result(n, 0);
        int left = 0;
        int right = n - 1;
        int index = n - 1;
        while (left <= right) {
            if (nums[left] * nums[left] > nums[right] * nums[right]) {
                result[index] = nums[left] * nums[left];
                left++;
            } else {
                result[index] = nums[right] * nums[right];
                right--;
            }
            index--;
        }
        return result;
    }
};

int main() {
    std::vector<int> nums = {-4, -1, 0, 3, 10};
    Solution s;
    std::vector<int> result = s.sortedSquares(nums);
    for (int i : result) {
        std::cout << i << " ";
    }
}