/**
* @file      reverse_string.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     344.反转字符串
* 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
* 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
* 示例 1：
* 输入：["h","e","l","l","o"]
* 输出：["o","l","l","e","h"]
* https://leetcode.cn/problems/reverse-string/description/
* @date      24-8-15
* @copyright Copyright (c) 2024
*/


#include <iostream>
#include <vector>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        int len = s.size();
        // 条件也可以是 i < size / 2
        for(int left = 0, right = len - 1; left < right; left++, right--) {
            std::swap(s[left], s[right]);
        }
    }
};


int main() {
    std::vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    Solution s;
    s.reverseString(str);
    for (auto c : str) {
        std::cout << c << " ";
    }
}
