/**
* @file      letter_combinations_of_a_phone_number.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC 17.电话号码的字母组合
* 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
* 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
* https://www.programmercarl.com/0017.%E7%94%B5%E8%AF%9D%E5%8F%B7%E7%A0%81%E7%9A%84%E5%AD%97%E6%AF%8D%E7%BB%84%E5%90%88.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-1
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    const string letterMap[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

public:
    vector<string> res;
    string path;    // 路径 存储结果

    /**
     * Backtracking func
     * @param digits 输入的数字字符串 const引用<br>
     * @param idx 数字字符串的索引 注意不是startIdx 因为此时树层数就是
     * 遍历的深度，现在的集合是数字字符串的集合，多个集合之间互相不影响
     */
    void backtracking(const string& digits, int idx) {
        // 终止条件
        if(idx == digits.size()) {  // 当前路径长度等于输入字符串长度
            res.push_back(path);
            return;
        }

        int digit = digits[idx] - '0';  // 当前数字
        string letters = letterMap[digit];  // 当前数字对应的字母集合

        for(auto letter : letters) {
            path.push_back(letter);
            backtracking(digits, idx + 1);  // 处理下一层数字 idx + 1
            path.pop_back();    // 回溯
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {
            return res;
        }
        path.clear();
        res.clear();
        backtracking(digits, 0);
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> res = sol.letterCombinations("23");
    for(auto str : res) {
        cout << str << endl;
    }
    return 0;
}