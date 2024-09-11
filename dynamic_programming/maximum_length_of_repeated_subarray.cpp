/**
* @file      maximum_length_of_repeated_subarray.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #718. 最长重复子数组
* https://www.programmercarl.com/0718.%E6%9C%80%E9%95%BF%E9%87%8D%E5%A4%8D%E5%AD%90%E6%95%B0%E7%BB%84.html#%E6%80%9D%E8%B7%AF
* @date      24-9-10
* @copyright Copyright (c) 2024
*/

#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // dp[i][j]代表以nums1以i结尾 nums2以j结尾的最长重复子数组
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
        int res = 0;
        for(int j = 0; j < nums2.size(); j++){
            if(nums1[0] == nums2[j]){
                dp[0][j] = 1;
                res = 1;
            }
        }
        for(int i = 0; i < nums1.size(); i++){
            if(nums2[0] == nums1[i]){
                dp[i][0] = 1;
                res = 1;
            }
        }
        // 如果从1开始遍历 那么res记得在上面出现为1时更新为1
        for(int i = 1; i < nums1.size(); i++){
            for(int j = 1; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]) {
                    // [i, j]结尾最长重复字串为[i - 1, j - 1]最长重复子串+1
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if(dp[i][j] > res)  res = dp[i][j];
            }
        }

        return res;
    }
};