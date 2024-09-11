/**
* @file      delete_operation_for_two_strings.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #583. 两个字符串的删除操作
* 给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。
* @date      24-9-11
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j]：以i-1为结尾的字符串word1，和以j-1位结尾的字符串word2，想要达到相等，所需要删除元素的最少次数
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        // 这里需要初始化 对于空串来说，要变成另一个字符串，只能删除所有字符
        for(int i = 0; i <= word1.size(); i++)  dp[i][0] = i;
        for(int j = 0; j <= word2.size(); j++)  dp[0][j] = j;
        for(int i = 1; i <= word1.size(); i++){
            for(int j = 1; j <= word2.size(); j++){
                if(word1[i - 1] == word2[j - 1]){
                    // 相等的话 只要前面[0, i-2]和[0, j-2]的状态转移过来即可
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 三种情况：删除word1[i - 1]，删除word2的[j - 1]，或者同时删除 取最小
                    // min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2)
                    // 第三种情况可以合并在前两种里面 可以按照步骤考虑 先考虑不删word1[i - 1] -> dp[i][j - 1]
                    // dp[i][j - 1]已经不考虑word2[j - 1]了，那么如果再把word1[i - 1]删掉就是dp[i][j - 1] + 1
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }
};

/*
 * 第二种思路：找到最短的修改步数可以找到最长的共同字串长度
 * 最后返回两个字符串长度和减去最长的共同字串长度*2
 */
int main() {
    Solution s;
    cout << s.minDistance("sea", "eat") << endl;
    return 0;
}
