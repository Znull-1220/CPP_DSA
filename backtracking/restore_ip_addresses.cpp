/**
* @file      restore_ip_addresses.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #93.复原IP地址
* 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
* 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址
* 但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
*
* 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效IP地址，
* 这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按任何顺序返回答案。
* https://www.programmercarl.com/0093.%E5%A4%8D%E5%8E%9FIP%E5%9C%B0%E5%9D%80.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-1
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// 本质也是切割字符串 和分割回文串的思路比较相似，只不过这里需要加'.' 以及判断是否有效
class Solution {
    vector<string> res; // 一维就够了，因为这里是在原字符串上进行回溯

    // 判断字符串s在左闭右闭区间[start, end]所组成的数字是否合法
    bool isVaild(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        // 不能含有前导0 注意这里'0'是个char类型而不是int 不能直接和0比较 第一次出错就是这个问题
        if(s[start] == '0' && start != end) {
            return false;
        }
        int sum = 0;
        for(int i = start; i <= end; i++) {
            // 检查数字合法性
            if(s[i] > '9' || s[i] < '0') {
                return false;
            }
            sum = sum * 10 + s[i] - '0';    // 每一次都判断
            if(sum > 255) {
                return false;
            }
        }

        return true;
    }

    void backtracking(string s, int startIdx, int pointNum) {
        // 终止条件 分割加了三次'.'那么是一个叶子节点，结束
        if(pointNum == 3) {
            if(isVaild(s, startIdx, s.size() - 1)) {
                res.push_back(s);
            }
            return;
        }

        for (int i = startIdx; i < s.size(); i++) {
            if(isVaild(s, startIdx, i)) {
                s.insert(s.begin() + i + 1, '.');   // 在i的后面插入'.'
                pointNum++;
                backtracking(s, i + 2, pointNum);   // i + 2 是因为插入了一个'.'
                pointNum--;
                s.erase(s.begin() + i + 1); // 回溯 删去插入的'.'
            } else
                break;
        }

    }
public:
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        if(s.size() < 4 || s.size() > 12) { // 从长度上来剪枝 但其实区别不大因为后面还是要判断是否合法
            return res;
        }
        backtracking(move(s), 0, 0);
        return res;
    }
};

int main() {
    Solution solution;
    // string s = "25525511135";
    // vector<string> res = solution.restoreIpAddresses(s);
    // for(const auto& str : res) {
    //     cout << str << endl;
    // }
    string s2 = "101023";
    vector<string> res2 = solution.restoreIpAddresses(s2);
    for(const auto& str : res2) {
        cout << str << endl;
    }
}