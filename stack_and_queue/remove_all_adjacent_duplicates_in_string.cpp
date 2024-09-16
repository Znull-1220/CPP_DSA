/**
* @file      remove_all_adjacent_duplicates_in_string.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #1047. 删除字符串中的所有相邻重复项
* 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
* 在 S 上反复执行重复项删除操作，直到无法继续删除。
* 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一
* https://www.programmercarl.com/1047.%E5%88%A0%E9%99%A4%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E6%89%80%E6%9C%89%E7%9B%B8%E9%82%BB%E9%87%8D%E5%A4%8D%E9%A1%B9.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-15
* @copyright Copyright (c) 2024
*/
// "abbaca" -> "ca"
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string& s) {
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i < s.size(); i++) {
            if(!st.empty() && s[i] == st.top())    st.pop();
            else    st.push(s[i]);
        }
        // 翻转字符串
        string res = "";
        while(!st.empty()) {
            res.insert(res.begin(), st.top());
            st.pop();
        }

        return res;
    }
};

int main() {
    Solution s;
    string str = "abbaca";
    cout << s.removeDuplicates(str) << endl;
    return 0;
}
