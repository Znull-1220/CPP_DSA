/**
* @file      evaluate_reverse_polish_notation.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #150. Reverse Polish notation(RPN)表达式求值
* https://www.programmercarl.com/0150.%E9%80%86%E6%B3%A2%E5%85%B0%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B1%82%E5%80%BC.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-15
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef long long ll;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<ll> stk;
        for(auto token : tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                ll nums2 = stk.top();
                stk.pop();
                ll nums1 = stk.top();
                stk.pop();
                if(token == "+") stk.push(nums1 + nums2);
                else if(token == "-") stk.push(nums1 - nums2);
                else if(token == "*") stk.push(nums1 * nums2);
                else if(token == "/") stk.push(nums1 / nums2);
            } else {
                // std::stoll()将字符串转换为long long类型 string to long long
                // std::stoi()将字符串转换为int类型 string to int
                stk.push(stoll(token));
            }
        }
        return stk.top();
    }
};

int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    Solution s;
    cout << s.evalRPN(tokens) << endl;
    return 0;
}