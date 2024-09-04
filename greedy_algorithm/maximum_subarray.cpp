/**
* @file      maximum_subarray.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #53. 最大子序和
* 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
* 子数组是数组中的一个连续部分。
* https://www.programmercarl.com/0053.%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%92%8C.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-4
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;   // 初始为最小值 避免输入全负数结果得0的情况
        int sum = 0;
        for(auto num : nums) {
            sum += num;
            // sum更大时更新result
            if(sum > result) {
                result = sum;
            }
            // 小于0时重置sum    贪心的目标是使连续和最大
            // 连续和为负，就重新选择起始位置
            // 因为sum更大时就会直接更新result，所以不会出现小负数累加使连续和结果变小的情况
            if(sum < 0) {
                sum = 0;
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout << s.maxSubArray(nums) << endl;

    return 0;
}
