/**
* @file      house_robber_ii.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     213.打家劫舍II
* 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈
* 这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻
* 的房屋在同一晚上被小偷闯入，系统会自动报警
* 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。
* https://www.programmercarl.com/0213.%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8DII.html#%E6%80%9D%E8%B7%AF
* @date      24-9-11
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * 有环的情况 其实可以分为三种
     * 1. 去最后一个元素 保留第一个元素
     * 2. 去第一个元素 保留最后一个元素
     * 3. 首尾两个元素都去掉
     * 第三种情况包含在第一种和第二种情况中 所以考虑前两种情况即可；那么后面就是打家劫舍I的问题了
     */
    int rob(vector<int>& nums) {
        if(nums.size() == 1)    return nums[0];
        if(nums.size() == 2)    return max(nums[0], nums[1]);
        int case1 = robRange(nums, 0, nums.size() - 2);
        int case2 = robRange(nums, 1, nums.size() - 1);
        int res = max(case1, case2);

        return res;
    }

    int robRange(vector<int>& nums, int startIdx, int endIdx) {
        vector<int> dp(endIdx - startIdx + 1, 0);
        dp[0] = nums[startIdx];
        dp[1] = max(nums[startIdx], nums[startIdx + 1]);
        for(int i = 2; i <= endIdx - startIdx; i++) {
            // 本来startIdx = 0的话 是nums[i]
            dp[i] = max(dp[i - 2] + nums[startIdx + i], dp[i - 1]);
        }

        return dp[endIdx - startIdx];
    }
};

int main() {
    vector<int> nums = {2, 3, 2};
    Solution solution;
    cout << solution.rob(nums) << endl;

    return 0;
}