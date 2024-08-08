/**
* @file      purchase_land.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     开发商购买土地
* 在一个城市区域内，被划分成了n * m个连续的区块，每个区块都拥有不同的权值，代表着其土地价值。
* 目前，有两家开发公司，A 公司和 B 公司，希望购买这个城市区域的土地。
* 现在，需要将这个城市区域的所有区块分配给 A 公司和 B 公司。
* 然而，由于城市规划的限制，只允许将区域*按横向或纵向*划分成两个子区域，而且每个子区域都必须包含一个或多个区块。
* 为了确保公平竞争，你需要找到一种分配方式，使得 A 公司和 B 公司各自的子区域内的土地总价值之差最小。
*
* refer: https://kamacoder.com/problempage.php?pid=1044
* @date      24-8-8
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main() {
    int m;
    int n;
    cin >> m >> n;
    vector<vector<int>> vec(m, vector<int>(n, 0));  // m * n
    // 可以用前缀和但没必要
    //vector<int> sum_on_row(m, 0);
    //vector<int> sum_on_col(n, 0);

    // 使用在行/列末尾统计总和的方法

    int sum = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> vec[i][j];
            sum += vec[i][j];
        }
    }

    int result = INT32_MAX;

    int cut_row = 0;
    int cut_col = 0;

    int divide = 0;

    // 按行横向切割
    for(cut_row = 0; cut_row < m; cut_row++) {
        for(int i = 0; i < m; i++) {
            divide += vec[cut_row][i];

            if(i == n - 1) {
                result = abs(sum - divide - divide) < result ? abs(sum - divide - divide) : result;
            }
        }
    }

    divide = 0; // 记得清零

    // 按列分割
    for(cut_col = 0; cut_col < n; cut_col++) {
        for(int i = 0; i < n; i++) {
            divide += vec[i][cut_col];

            if(i == m - 1) {
                result = abs(sum - divide - divide) < result ? abs(sum - divide - divide) : result;
            }
        }
    }

    cout << result << endl;
}
