/**
* @file      climbing_stairs_ii.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     Kamacoder 57. 爬楼梯（第八期模拟笔试）
* https://www.programmercarl.com/0070.%E7%88%AC%E6%A5%BC%E6%A2%AF%E5%AE%8C%E5%85%A8%E8%83%8C%E5%8C%85%E7%89%88%E6%9C%AC.html#%E6%80%9D%E8%B7%AF
* @date      24-9-9
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;  // n: 楼梯数，m: 每次最多能爬的步数
    // 那么其实就转换成了一个完全背包问题 因为爬的顺序不同也是不同的方案 所以是一个排列问题
    // n 最大容量； m 1-m为物品 每次能爬[1, m]步 这和之前斐波那契数列的爬楼梯问题是不同的(每次仅1/2步)
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int j = 1; j <= n; j++) {
        for(int i = 1; i <= m; i++) {
            if(i <= j) {
                dp[j] += dp[j - i];
            }
        }
    }

    cout << dp[n] << endl;
}