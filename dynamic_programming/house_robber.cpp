/**
* @file      house_robber.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC 198. 打家劫舍
* @date      24-9-11
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // 开始忘记判断为1的情况了
        if(nums.size() == 1)    return nums[0];
        // dp[i]的含义是 考虑下标i（包括i）以内的房屋，最多可以偷窃的金额为dp[i]
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            // 状态转移：打劫第i间房子 或者不偷第i间 那么直接将第i- 1间的最大值转移过来
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[nums.size() - 1];
    }
};

int main(){
    vector<int> nums = {2, 7, 9, 3, 1};
    Solution s;
    int res = s.rob(nums);
    cout << res << endl;
    return 0;
}