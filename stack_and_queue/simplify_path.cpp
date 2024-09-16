/**
* @file      simplify_path.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #71 简化路径
* https://leetcode.cn/problems/simplify-path/description/
* @date      24-9-16
* @copyright Copyright (c) 2024
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        // Lambda func 这里的auto类型是function<string(const string&, char)>，split储存的是一个函数对象
        auto split = [](const string& path, char delim) -> vector<string> {
            string cur;
            vector<string> ans;
            for(char c : path) {
                if(c == delim) {    // 遇到定界符 就push 当前子字符串cur 并且清空cur
                    ans.push_back(move(cur));
                    cur.clear();
                } else {
                    cur += c;
                }
            }
            // 最后一个子字符串后面可能没有定界符 直接push进去 就算有那么cur是空串也不影响
            ans.push_back(move(cur));
            return ans;
        };

        vector<string> splits = split(path, '/');
        vector<string> stack;   // vec模拟stack
        for(auto seg : splits) {
            if(seg == "..") {
                // 不空的时候才pop一个 回到上级目录 否则直接跳过这个返回上级目录的操作
                // 如果不放在这里而是和seg一起判断不为空的话 那么不满足直接进入下面的分支了
                if(!stack.empty()){
                    stack.pop_back();
                } else {
                    continue;
                }

            } else if(seg == "." || seg == "") {
                continue;
            } else {
                stack.push_back(seg);
            }
        }

        string ans;
        // 如果stack为空 说明路径是根目录
        if(stack.size() == 0) {
            ans += "/";
        } else {
            for(auto seg : stack) {
                ans += "/";
                ans += seg;
            }
        }

        return ans;
    }
};

int main() {
    string path = "/home/user/Documents/../Pictures";
    Solution s;
    cout << s.simplifyPath(path) << endl;
    return 0;
}