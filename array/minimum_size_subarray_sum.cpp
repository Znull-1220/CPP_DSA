/**
* @file      minimum_size_subarray_sum.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     Leetcode 209: 长度最小的子数组
* 给定一个含有 n 个正整数的数组和一个正整数 s
* 找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0
* refer https://leetcode.cn/problems/minimum-size-subarray-sum/
* @date      24-8-8
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <cstdint>

class Solution {
public:
    /**
     * 暴力解法
     * @param num 相加的目标值
     * @param nums 输入vector
     * @return 最小subarray长度
     */
    int min_sub_array_len(int num, std::vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            for(int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum >= num) {
                    int sub_length = j - i + 1;
                    result = result < sub_length ? result : sub_length;
                    // result = std::min(result, j - i + 1);
                    break;
                }

            }
            sum = 0;
        }
        return result == INT32_MAX ? 0 : result;
    }

    /**
     * 滑动窗口 也可以理解为双指针 O(n)
     * @param num
     * @param nums
     * @return
     */
    int min_sub_array_len2(int num, std::vector<int>& nums) {
        int result = INT32_MAX;
        int sub_length = 0;
        int sum = 0;
        int i = 0;  // 滑动窗口的左边界
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 当sum >= num 时，缩小窗口, 是用循环做所以此时右边界不动
            while (sum >= num) {
                sub_length = j - i + 1;
                // 判断当前是否最短 这个之前遗漏了
                result = result < sub_length ? result : sub_length;
                sum -= nums[i++];   // 左边界右移 说明需要缩小窗口
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};


int main() {
    std::vector<int> nums = {2, 3, 1, 2, 4, 3};
    int sum = 8;
    Solution s;
    int res = s.min_sub_array_len(sum, nums);
    std::cout << res << std::endl;
    int result = s.min_sub_array_len2(sum, nums);
    std::cout << result << std::endl;
}
