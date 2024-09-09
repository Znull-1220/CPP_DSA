/**
* @file      complete_knapsack.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     完全背包 模板题
* https://kamacoder.com/problempage.php?pid=1052
* @date      24-9-8
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * @param weight weight vec
 * @param value value vec
 * @param v 背包容量volume
 * @return 最大价值
 */
int completeKnapsack(vector<int>& weight, vector<int>& value, int v){
    vector<int> dp(v + 1, 0);
    for(int i = 0; i < weight.size(); i++){
        // 第一次把volume本身漏掉了！ <=
        for(int j = weight[i]; j <= v; j++){
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    return dp[v];
}

int main(){
    int n, v;
    cin >> n >> v;
    vector<int> weight;
    vector<int> value;
    for(int i = 0; i < n; i++){
        int w, val;
        cin >> w >> val;
        weight.push_back(w);
        value.push_back(val);
    }

    int maxVal = completeKnapsack(weight, value, v);
    cout << maxVal << endl;
    return 0;
}