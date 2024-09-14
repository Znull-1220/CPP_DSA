/**
* @file      next_greater_element_ii.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     503.下一个更大元素II
* 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。
* 数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该
* 循环地搜索它的下一个更大的数。如果不存在，则输出 -1
* https://www.programmercarl.com/0503.%E4%B8%8B%E4%B8%80%E4%B8%AA%E6%9B%B4%E5%A4%A7%E5%85%83%E7%B4%A0II.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-13
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> stk;
        stk.push(0);
        // 2*n 模拟走两遍的过程
        for(int i = 1; i < n * 2; i++) {
            if(nums[i % n] <= nums[stk.top()]) {
                stk.push(i % n);
            } else {
                // 注意 逻辑短路 先判断是否为空
                // 之前后判断为空 报错Line 170: Char 16: runtime error: reference binding to misaligned address
                // 就是访问了空栈的top
                while(!stk.empty() && nums[i % n] > nums[stk.top()]) {
                    res[stk.top()] = nums[i % n];
                    stk.pop();
                }
                stk.push(i % n);
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 1};
    Solution sl;
    vector<int> res = sl.nextGreaterElements(nums);
    for(auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}