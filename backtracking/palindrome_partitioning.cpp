/**
* @file      palindrome_partitioning.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #131.分割回文串
* 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
* 返回 s 所有可能的分割方案。
* 示例: 输入: "aab" 输出: [ ["aa","b"], ["a","a","b"] ]
* https://www.programmercarl.com/0131.%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-1
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<string>> res;
    vector<string> path;

    bool isPalindrome(const string& s, int start, int end) {    // 基本的双指针方法 还能继续优化
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    void backtracking(int startIdx, const string& s) {
        // 递归终止条件
        if(startIdx >= s.size()) {
            res.push_back(path);
            return;
        }

        for(int i = startIdx; i < s.size(); i++) {
            // 判断当前子串 是否是回文串 startIdx就是切割线
            if(!isPalindrome(s, startIdx, i)) {
                continue;   // 如果当前这里不是回文串，那么也就不用继续往下切割了
            } else {
                // 当前是回文串，就继续尝试往下切割
                // [startIdx, i] 区间的字串 substr第二个参数是长度
                string subStr = s.substr(startIdx, i - startIdx + 1);
                path.push_back(subStr);
            }
            backtracking(i + 1, s); // 可以看作组合问题，因为前面截取过的后面不再要了 所以i + 1
            path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        res.clear();
        path.clear();
        backtracking(0, s);
        return res;
    }
};


int main() {
    Solution solution;
    string s = "aab";
    vector<vector<string>> res = solution.partition(s);
    for(auto& v : res) {
        for(auto& str : v) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}