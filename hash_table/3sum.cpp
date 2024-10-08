/**
* @file      3sum.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     Leetcode #15. 三数之和
* 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0?
* 请你找出所有满足条件且不重复的三元组。注意： 答案中不可以包含重复的三元组
* 示例：
* 给定数组 nums = [-1, 0, 1, 2, -1, -4]
* 满足要求的三元组集合为： [ [-1, 0, 1], [-1, -1, 2] ]
* https://leetcode.cn/problems/3sum/description/
* @date      24-8-14
* @copyright Copyright (c) 2024
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * 双指针法
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        // 从小到大排序
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if (nums[i] > 0) {
                return result;
            }
            // 错误去重a方法，将会漏掉-1,-1,2 这种情况
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
            // 正确去重a方法，等于是在上一轮循环考虑当前a 两个元素相等这种情况
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */

                // 大于0说明数字大了，右边right--，小于0说明数字小了，左边left++
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    // 这是push一个vector到二位vector
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
                    // 为什么不同时++/--，是因为一个数字变动后不可能再找到相同的三元组了，除非另一个数字也变动
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }

        }
        return result;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution solution;
    vector<vector<int>> result = solution.threeSum(nums);
    // auto& 这样使用ref传递就避免不断复制的问题
    for (auto& vec : result) {
        for (auto& num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}