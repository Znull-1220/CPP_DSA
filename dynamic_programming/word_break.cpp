/**
* @file      word_break.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #139. 单词拆分
* 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
* 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
* https://www.programmercarl.com/0139.%E5%8D%95%E8%AF%8D%E6%8B%86%E5%88%86.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-9
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution1 {
private:
    /**
    * 回溯解法 使用记忆化递归降低时间复杂度
    * @param s 字符串
    * @param wordSet 字典集合 便于查找
    * @param memory 记忆数组 表征以startIdx为起点的字符串是否能被拆分 初始都为true
    * @param startIdx 当前字符串的递归起始位置
    * @return 如果能被拆分 返回True，否则返回false.
    */
    bool backtracking(const string& s, unordered_set<string>& wordSet, vector<bool>& memory, int startIdx) {
        // 递归终止条件 递归到字符串末尾
        if(startIdx == s.size()) {
            return true;
        }
        // 记忆化递归 就只标记不可拆分的字符串
        if(memory[startIdx] == false) {
            return false;
        }
        for(int i = startIdx; i < s.size(); i++) {
            string subStr = s.substr(startIdx, i - startIdx + 1);
            if (wordSet.find(subStr) != wordSet.end() && backtracking(s, wordSet, memory, i + 1)) {
                return true;
            }
        }

        memory[startIdx] = false;   // 以startIdx为起点的字符串不能被拆分
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> memory(s.size(), -1);
        return backtracking(s, wordSet, memory, 0);
    }
};


class Solution2 {
public:
    /**
     * DP解法
     */
    bool wordBreak(const string& s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        // dp[i] 表示以i为结尾的字符串是否能被拆分为一个/多个字典中的单词
        vector<bool> dp(s.size() + 1, false);
        // 因为字典中的单词都能无限使用-> 完全背包问题；
        // 假设dp[j] = true 如果s[j ~ i]在字典中，则dp[i] = true
        // 递推公式则为 dp[i] = dp[i] || dp[j] && s.substr(j, i - j) in wordDict
        dp[0] = true;   // 推一下后面在dict中的第一个单词dp数组就知道
        // 因为字符串组成有顺序 所以是排列问题 先遍历背包再遍历物品
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                string subStr = s.substr(j, i - j);
                if (wordSet.find(subStr) != wordSet.end() && dp[j]) {
                    dp[i] = true;
                }
            }
        }

        return dp[s.size()];
    }
};


int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    Solution1 solution;
    cout << solution.wordBreak(s, wordDict) << endl;
    return 0;
}