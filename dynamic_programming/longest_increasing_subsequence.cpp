/**
* @file      longest_increasing_subsequence.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #300.最长递增子序列
* 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
* 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7]
* 是数组 [0,3,1,6,2,2,7] 的子序列。
* @date      24-9-10
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1)    return nums.size();
        // dp[i]表示以nums[i]结尾的最长递增子序列的长度
        vector<int> dp(nums.size(), 1);
        // 因为dp[i]是以nums[i]结尾的最长递增子序列的长度，所以需要一个变量不断记录更新最大值
        // 因为最大值不一定出现在最后一个元素处(最后一个元素没有前面最长的结尾元素大，转移不了状态)
        int result = 1;
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    result > dp[i] ? result : result = dp[i];
                }
            }
            // for(auto elem : dp) {
            //     cout << elem << ' ';
            // }
            // cout << endl;
        }
        return result;
    }
};

int main() {
    vector<int> nums = {1,3,6,7,9,4,10,5,6};
    Solution s;
    cout << s.lengthOfLIS(nums) << endl;
    return 0;
}