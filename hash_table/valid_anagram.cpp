/**
* @file      valid_anagram.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     Leetcode #242.有效的字母异位词
* https://leetcode.cn/problems/valid-anagram/description/
* 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词, 假设只有小写字母
* 示例 1: 输入: s = "anagram", t = "nagaram" 输出: true
* 示例 2: 输入: s = "rat", t = "car" 输出: false
* @date      24-8-12
* @copyright Copyright (c) 2024
*/

#include <iostream>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};   // 因为26个字母，所以hash table定为26就可以
        // 统计s中每个字母出现的次数，映射到hash table中
        for (int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
        }
        // 统计t中每个字母出现的次数，映射到hash table中, 这次做减法
        for(char i : t) {
            record[i - 'a']--;
        }

        for(int i : record) {
            // 如果不为0，说明s和t中的字母出现次数不一样
            if(i != 0) {
                return false;
            }
        }

        return true;
    }
};


int main() {
    string s = "anagram";   // std::string 是一个对象
    string t = "nagaram";
    Solution solution;
    cout << solution.isAnagram(s, t) << endl;
}