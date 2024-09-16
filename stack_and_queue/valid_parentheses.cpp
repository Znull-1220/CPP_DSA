/**
* @file      valid_parentheses.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     20. 有效的括号
* 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
* 有效字符串需满足：
* 左括号必须用相同类型的右括号闭合
* 左括号必须以正确的顺序闭合
* 注意空字符串可被认为是有效字符串
* https://www.programmercarl.com/0020.%E6%9C%89%E6%95%88%E7%9A%84%E6%8B%AC%E5%8F%B7.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-15
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0) {
            return false;   // 如果字符串长度为奇数，直接返回false
        }
        stack<char> st;
        /*
         * 不匹配的情况：
         * 1. 左边括号多了 2. 右边括号多了 3. 左右括号不匹配
         */
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')     st.push(')');
            else if(s[i] == '[')    st.push(']');
            else if(s[i] == '{')    st.push('}');
            // 如果栈为空或者栈顶元素不等于当前元素，直接返回false
            // 栈空说明右括号多了，栈顶元素不等于当前元素说明左右括号不匹配
            else if(st.empty() || st.top() != s[i]) {
                return false;
            } else {
                st.pop();
            }
        }

        // 遍历结束 但栈不为空，说明左括号多了 不匹配
        if(!st.empty())     return false;
        else   return true;
    }
};


int main() {
    Solution s;
    string str = "()";
    cout << s.isValid(str) << endl;
    return 0;
}