/**
* @file      distinct_subsequences.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     115. 不同的子序列
* 给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数，结果需要对 109 + 7 取模
* https://www.programmercarl.com/0115.%E4%B8%8D%E5%90%8C%E7%9A%84%E5%AD%90%E5%BA%8F%E5%88%97.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-11
* @copyright Copyright (c) 2024
*/
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

class Solution {
public:
    int numDistinct(string s, string t) {
        // dp数组的含义是以s中以i - 1结尾的子字符串出现t中以j - 1结尾的字符串的个数为dp[i][j]
        vector<vector<ull>> dp(s.size() + 1, vector<ull>(t.size() + 1, 0));
        // 如果t是空字符串 s可以任意删除 那么s中任意字符结尾的字符串都可以被删为空串
        // dp[0][0]表示s&t为空串 s删0个字符就和t一样 所以是1
        for(int i = 0; i <= s.size(); i++)  dp[i][0] = 1;
        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= t.size(); j++){
                if(s[i - 1] == t[j - 1]){
                    // s[i - 1] == t[j - 1] 说明s[i - 1]可以和t[j - 1]匹配 那么dp[i][j]就可以由dp[i - 1][j - 1]转移过来
                    // 匹配的情况下还可以选择不用s[i - 1]匹配(也就是模拟s中删除这个字符) 那么dp[i][j]就可以由dp[i - 1][j]转移过来
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else{
                    // 不相等时 只能模拟在s中删除s[i - 1]字符
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[s.size()][t.size()];
    }
};