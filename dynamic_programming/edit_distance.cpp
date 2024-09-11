/**
* @file      edit_distance.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #72. 编辑距离
* 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数
* 你可以对一个单词进行如下三种操作：
* 插入一个字符
* 删除一个字符
* 替换一个字符
* https://www.programmercarl.com/0072.%E7%BC%96%E8%BE%91%E8%B7%9D%E7%A6%BB.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-11
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j] 表示word1的前i - 1个字符转换成word2的前j - 1个字符所需要的最少操作数
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        // 初始化 不是空串的话都要删除到空串
        for(int i = 0; i <= word1.size(); i++)  dp[i][0] = i;
        for(int j = 0; j <= word2.size(); j++)  dp[0][j] = j;
        for(int i = 1; i <= word1.size(); i++){
            for(int j = 1; j <= word2.size(); j++){
                // 如果相等 那么不用任何操作 直接从[0~i - 2]和[0~j - 2]转移过来即可
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // {} is necessary 这是一个initializer_list 需要#include <algorithm>
                    /*
                     * 不相等的话有三种情况：
                     * 1. word1删除一个 那么就是前面的[0~i - 2]和[0~j - 1]转移过来 dp[i - 1][j] + 1
                     * 2. word2删除一个 那么就是前面的[0~i - 1]和[0~j - 2]转移过来 dp[i][j - 1] + 1
                     * word2删除一个 等价于 word1插入一个
                     * 3. word1替换一个 那么就是前面的[0~i - 2]和[0~j - 2]转移过来 dp[i - 1][j - 1] + 1
                     */
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }
};

int main() {
    Solution solution;
    string word1 = "horse";
    string word2 = "ros";
    cout << solution.minDistance(word1, word2) << endl;
    return 0;
}