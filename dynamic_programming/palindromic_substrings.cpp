/**
* @file      palindromic_substrings.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #647. 回文子串
* 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
* 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
* @date      24-9-12
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

/*
 * 1 DP思路
 */
class Solution1 {
public:
    int countSubstrings(string s) {
        // dp[i][j]代表[i, j]的子串 是否为回文字符串
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        // 如果两个字符中间所夹的子串为回文串&&两个字符相等 那么这个字符串就为回文串
        int res = 0;
        // 即dp[i + 1][j - 1] 在dp[i][j]的左下方 所以遍历顺序一定是 从下到上 从左到右
        for(int i = s.size() - 1; i >= 0; i--) {
            for(int j = i; j < s.size(); j++) {
                if(s[i] == s[j]) {
                    // 字符串 i = j 为一个字符的情况
                    // 或者 s[i]s[j] e.g. aa 两个字符相等的情况
                    if(j - i <= 1) {
                        res++;
                        dp[i][j] = true;
                    } else if (dp[i + 1][j - 1]) {
                        res++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        // 最后遍历出来的dp table 是个上三角矩阵
        return res;
    }
};

/*
 * 思路2 双指针 + 中心扩展
 * 在遍历中心点的时候，要注意中心点有两种情况    奇数/偶数
 * 一个元素可以作为中心点，两个元素也可以作为中心点
 * 那么向两边分别扩散，直到不是回文串为止
 */
class Solution2 {
public:
    int countSubstrings(string s) {
        int len = s.size();
        int res = 0;
        for(int i = 0; i < len; i++) {
            res += extend(s, i, i, len);
            res += extend(s, i, i + 1, len);
        }

        return res;
    }

    int extend(string &s, int startIdx, int endIdx, int len) {
        int res = 0;
        while (startIdx >= 0 && endIdx < len && s[startIdx] == s[endIdx]) {
            res++;
            startIdx--;
            endIdx++;
        }

        return res;
    }
};

int main() {
    Solution1 s;
    cout << s.countSubstrings("aba") << endl;
    Solution2 s2;
    cout << s2.countSubstrings("aba") << endl;
    return 0;
}