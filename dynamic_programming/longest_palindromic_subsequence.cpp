/**
* @file      longest_palindromic_subsequence.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #516.最长回文子序列
* 给定一个字符串 s，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000
* 示例: 输入: "bbbab" 输出: 4 一个可能的最长回文子序列为 "bbbb"
* https://www.programmercarl.com/0516.%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E5%BA%8F%E5%88%97.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-12
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // dp[i][j]代表[i, j]的子串 最长回文子序列的长度
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        // 初始化 单个字符一定是回文串
        for(int i = 0; i < s.size(); i++)   dp[i][i] = 1;
        // 要初始化的原因是 因为递推公式是dp[i][j] = dp[i + 1][j - 1] + 2
        // 不初始化主对角线 会导致越界 就是如果i = j那么i + 1 > j - 1 跟dp table的定义不符
        // dp[i][j] 由左下方 下方和左方的值决定 所以遍历顺序一定是 从下到上 从左到右
        for(int i = s.size() - 1; i >= 0; i--) {
            // 其实这个起始位置 从dp table的定义来看很显然
            // dp table 一定是个上三角阵 那么已经初始化过主对角线 就从i + 1开始即可
            for(int j = i + 1; j < s.size(); j++) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        // [0, s.size() - 1]的子串的最长回文子序列 定义明确
        return dp[0][s.size() - 1];
    }
};

int main() {
    Solution s;
    cout << s.longestPalindromeSubseq("bbbab") << endl;
    return 0;
}