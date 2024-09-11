/**
* @file      is_subsequence.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #47 判断子序列
* https://www.programmercarl.com/0392.%E5%88%A4%E6%96%AD%E5%AD%90%E5%BA%8F%E5%88%97.html#%E6%80%9D%E8%B7%AF
* @date      24-9-11
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 判断s是否是t的子序列
     */
    bool isSubsequence(string s, string t) {
        // dp[i][j] 表示以下标i-1为结尾的字符串s，和以下标j-1为结尾的字符串t，相同子序列的长度为dp[i][j]
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= t.size(); j++){
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else{
                    // 和最长公共子序列很像 但这里只能删除t的字符 所以只能从dp[i][j-1]转移
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        if(dp[s.size()][t.size()] == s.size())    return true;
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isSubsequence("abc", "ahbgdc") << endl;
    return 0;
}
// 这道题用最长公共子序列的思路来做，也可以AC，其实分析一下可以知道最长公共子序列只要等于子串长，那么肯定没有出现
// 删除t的字符的情况，但是 这里本质上只能删除t的字符 所以只能从dp[i][j-1]转移 这就是编辑距离