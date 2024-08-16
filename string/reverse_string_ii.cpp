/**
* @file      reverse_string_ii.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     541. 反转字符串II
* 给定一个字符串 s 和一个整数 k，从字符串开头算起, 每计数至 2k 个字符，就反转这 2k 个字符中的前 k 个字符。
* 如果剩余字符少于 k 个，则将剩余字符全部反转。
* 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
*
* 示例:
* 输入: s = "abcdefg", k = 2       输出: "bacdfeg"
* https://leetcode.cn/problems/reverse-string-ii/description/
* @date      24-8-16
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.length();
        for(int i = 0; i < len; i += 2 * k) {
            if(i + k > len) {
                reverse(s.begin() + i, s.end());
            }
            else {
                reverse(s.begin() + i, s.begin() + i + k);
            }
        }

        return s;
    }
};


int main() {
    string s = "abcdefg";
    int k = 2;
    Solution solution;
    cout << solution.reverseStr(s, k) << endl;
    return 0;
}