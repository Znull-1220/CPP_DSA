/**
* @file      last_stone_weight_ii.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #1049.最后一块石头的重量II
* 有一堆石头，每块石头的重量都是正整数。每一回合，从中选出任意两块石头，然后将它们一起粉碎。
* 假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
* 如果 x == y，那么两块石头都会被完全粉碎；
* 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x
* 最后，最多只会剩下一块石头。返回此石头最小的可能重量。如果没有石头剩下，就返回 0。
* https://www.programmercarl.com/1049.%E6%9C%80%E5%90%8E%E4%B8%80%E5%9D%97%E7%9F%B3%E5%A4%B4%E7%9A%84%E9%87%8D%E9%87%8FII.html#%E6%80%9D%E8%B7%AF
* @date      24-8-30
* @copyright Copyright (c) 2024
*/

#include<iostream>
#include <numeric>
#include<vector>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;

        // 这道题其实和分割等和子集是一样的，只不过这里是求最小的差值 所以规划为一个sum / 2 的背包 尽量装然后求差
        vector<int> dp(target + 1, 0);

        // 0/1背包
        for(int stone : stones) {
            for(int j = target; j >= stone; j--) {
                dp[j] = max(dp[j], dp[j - stone] + stone);
            }
        }

        return sum - 2 * dp[target];
    }
};


int main() {
    Solution solution;
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << solution.lastStoneWeightII(stones) << endl;
    return 0;
}