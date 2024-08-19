/**
* @file      reverse_words_in_a_string.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     151.翻转字符串里的单词 https://leetcode.cn/problems/reverse-words-in-a-string/description/
* 给定一个字符串，逐个翻转字符串中的每个单词。
* 示例 ：
* 输入: "a good   example"
* 输出: "example good a"
* 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
* @date      24-8-18
* @copyright Copyright (c) 2024
*/


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * 左闭右闭 [begin, end]
     * @param s input str
     * @param begin begin idx
     * @param end end idx
     */
    void reverse(string& s, int begin, int end) {
        for(; begin < end; begin++, end--) {
            swap(s[begin], s[end]);
        }
    }

    /**
     * 移除多余字符串 双指针法
     * 和array-移除元素中的思路一致，只不过这里是移除空格
     * 这里用earse fun来移除空格并不好，因为erase会导致后面的元素移动，时间复杂度是O(n)
     * @param s input string
     */
    void removeExtraSpaces(string &s) {
        int slow = 0;
        int fast = 0;
        // 对for loop来说 i++/++i没区别
        for(fast = 0; fast < s.length(); fast++) {
            // 只处理所有非space 即删除space
            if(s[fast] != ' ') {
                // 如果slow不等于0说明不是首个单词，就添加一个空格
                if(slow != 0) {
                    s[slow++] = ' ';
                }
                // 在后面补上这个单词
                // 如果第一个char是空格 那么也被后面的字符移动过来从而删除了
                while(s[fast] != ' ' && fast < s.length()) {
                    s[slow++] = s[fast++];
                }
            }
        }

        // resize 修改length而不是capacity， reserve 修改capacity
        s.resize(slow);
    }

    string reverseWords(string s) {
        removeExtraSpaces(s);
        // 整体的思路是，首先去除多余的空格，然后整体翻转，再单独翻转每个单词
        reverse(s, 0, s.length() - 1);

        int start = 0;
        for(int i = 0; i < s.length(); i++) {
            // 其实记录下标就OK了 中间不用特殊处理
            if(s[i] == ' ' || i == s.length() - 1) {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }

        return s;
    }
};


int main() {
    string s = " a good   example";
    Solution solution;
    string result = solution.reverseWords(s);   // 这个没用ref copy新的string
    cout << result << endl;
}