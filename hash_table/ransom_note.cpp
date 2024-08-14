/**
* @file      ransom_note.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     383. 赎金信
* 给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom
* 能不能由第二个字符串 magazines 里面的字符构成。如果可以构成，返回 true ；否则返回 false。
* (题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。
* 杂志字符串中的每个字符只能在赎金信字符串中使用一次。)
* https://leetcode.cn/problems/ransom-note/description/
* @date      24-8-14
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * 暴力解法
     */
    bool canConstruct1(string ransomNote, string magazine) {
        /*
         * note: 这里必须是遍历magazine作为外层循环，如果是以ransomNote作为外层循环，length的值会改变导致
         * 后面的字符无法被遍历到；而且就算遍历正确，也没有办法满足magazine string的字符只能使用一次的要求
         * 如果用foreach + 两次earse也可以，但这样复杂度会更高
         */
        for (int i = 0; i < magazine.length(); i++) {
            for (int j = 0; j < ransomNote.length(); j++) {
                // 在ransomNote中找到和magazine相同的字符
                if (magazine[i] == ransomNote[j]) {
                    //iterator erase(const_iterator p);：此重载方法用于删除迭代器 p 指向的字符
                    // 删除的是单个字符 其实iter跟指针很像
                    ransomNote.erase(ransomNote.begin() + j);
                    break;
                }
            }
        }
        // 如果ransomNote为空，则说明magazine的字符可以组成ransomNote
        if (ransomNote.empty()) {
            return true;
        }

        return false;
    }

    /**
     * 空间换时间的哈希策略
     */
    bool canConstruct2(const string& ransomNote, const string& magazine) {
        // 使用数组作为hash table, 因为固定大小26空间浪费更少，用map还要维护红黑树/哈希表 额外数据结构
        int record[26] = {0};

        for(char c : magazine) {
            record[c - 'a']++;
        }

        for(char c : ransomNote) {
            record[c - 'a']--;
            // 小于就说明肯定不足了 但大于是OK的因为没有要求完全一致的异位字符串
            if(record[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};


int main() {
    string a = "aa";
    string b = "aab";


    // string& erase(size_t pos = 0, size_t len = npos);
    // a.erase(0); 这样移除的是remainder of the string
    //a.erase(0, 1);

    Solution s;
    cout << s.canConstruct1(a, b) << endl;
    // 无需显式传递引用
    cout << s.canConstruct2(a, b) << endl;
}