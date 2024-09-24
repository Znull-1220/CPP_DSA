/**
* @file      lexicographical_numbers.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #386. 字典序排数
* https://leetcode.cn/problems/lexicographical-numbers/description/
* @date      24-9-24
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(int x, int y) {
        string s1 = to_string(x);
        string s2 = to_string(y);
        return s1 < s2;
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i = 1; i <= n; i++) {
            res.push_back(i);
        }
        sort(res.begin(), res.end(), cmp);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> res = s.lexicalOrder(13);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}