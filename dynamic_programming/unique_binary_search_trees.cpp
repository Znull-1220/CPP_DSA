/**
* @file      unique_binary_search_trees.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC 96.不同的二叉搜索树
* 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
* https://www.programmercarl.com/0096.%E4%B8%8D%E5%90%8C%E7%9A%84%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-8-26
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // 因为0也要算上 这里dp数组的含义是：dp[n]为数字为1-n时二叉搜索树的个数
        vector<int> dp(n + 1, 0);

        dp[0] = 1;  // 0个数字时，只有一种情况，即空树 空树只有一种可能，空树也是满二叉树
        dp[1] = 1;  // 1个数字时，只有一种情况，即根节点

        for(int i = 2; i <= n; i++) {   // n  Cuz idx begins from 1
            // 从前面推导后面所以是从小到大 因为后面的值依赖于前面的值
            // 举例dp[3]可以是：1为根节点，左子树有0个节点，右子树有2个节点；2为根节点，左子树有1个节点；
            // 右子树有1个节点；3为根节点，左子树有2个节点，右子树有0个节点 所以就是两边不同子树个数的乘积

            // 内层j的含义为 j为根节点时，左子树有j-1个节点，右子树有i-j个节点 j第一个数字是1 因为是1-n的二叉树
            for(int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};


int main() {
    Solution solution;
    int n = 5;
    cout << solution.numTrees(n) << endl;
    return 0;
}
