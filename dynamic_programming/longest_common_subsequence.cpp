/**
* @file      longest_common_subsequence.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #1143.最长公共子序列
* https://leetcode.cn/problems/longest-common-subsequence/description/
* https://www.programmercarl.com/1143.%E6%9C%80%E9%95%BF%E5%85%AC%E5%85%B1%E5%AD%90%E5%BA%8F%E5%88%97.html#%E6%80%9D%E8%B7%AF
* @date      24-9-10
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    /**
     * 第一种思路 dp[i][j]为 text1[i]和text2[j]结尾的最长公共子序列的长度
     * 需要初始化 但比较直观
     */
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
        int res = 0;
        for(int j = 0; j < text2.size(); j++){
            if(text1[0] == text2[j]) {
                for(int k = j; k < text2.size(); k++){
                    dp[0][k] = 1;
                }
                res = 1;
                break;
            }
        }
        for(int i = 0; i < text1.size(); i++){
            if(text2[0] == text1[i]){
                for(int k = i; k <text1.size(); k++){
                    dp[k][0] = 1;
                }
                res = 1;
                break;
            }
        }
        for(int i = 1; i < text1.size(); i++){
            for(int j = 1; j < text2.size(); j++){
                if(text1[i] == text2[j]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                if(dp[i][j] > res)  res = dp[i][j];
            }
        }

        return res;
    }
};

class Solution2 {
public:
    /**
     * dp[i][j]为 text1[i - 1]和text2[j - 1]结尾的最长公共子序列的长度
     * 这样写的好处就是不用初始化 直接开始递推就行
     * 这道题是不断在更新最大值 所以不需要res来记录更新 最后返回dp[text1.size()][text2.size()]即可
     */
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for(int i = 1; i <= text1.size(); i++){
            for(int j = 1; j <= text2.size(); j++){
                // 注意这里比较的是text1[i - 1]和text2[j - 1]
                // 因为dp[i][j]代表的是text1[i - 1]和text2[j - 1]结尾的最长公共子序列
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else{
                    // 如果不相等的话 那么最长记录为
                    // text1[0...i-1]和text2[0...j-2]的最长公共子序列
                    // 或者text1[0...i-2]和text2[0...j-1]的最长公共子序列
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[text1.size()][text2.size()];
    }
};

int main() {
    string text1 = "abc";
    string text2 = "def";
    Solution1 s1;
    cout << s1.longestCommonSubsequence(text1, text2) << endl;
    Solution2 s2;
    cout << s2.longestCommonSubsequence(text1, text2) << endl;
    return 0;
}