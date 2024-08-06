/**
 * @file binary_search.cpp
 * @author Jinghui Zhang (zhangjh1220@gmail.com)
 * @brief 二分查找: 给定一个 n 个元素有序的（升序）整型数组 nums
 * 和一个目标值 target, 写一个函数搜索 nums 中的 target, 如果
 * 目标值存在返回下标，否则返回 -1。
 * @date 2024-07-09
 *
 * @copyright Copyright (c) 2024
 */

#include <iostream>
#include <vector>

class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
        while (left <= right)
        {
            // int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
            int mid = left + ((right - left) / 2);
            if (nums[mid] == target)
            {
                return mid;
            }
            // target 在左区间，所以[left, middle - 1]
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            // target 在右区间，所以[middle + 1, right]
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
        }
        // Add a return statement for the case when target is not found
        return -1;
    }
};

int main()
{
    std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    Solution s;
    int res = s.search(nums, target);
    std::cout << res << std::endl;
    return 0;
}