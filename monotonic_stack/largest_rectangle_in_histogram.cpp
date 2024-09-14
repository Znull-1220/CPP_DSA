/**
* @file      largest_rectangle_in_histogram.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     84.柱状图中最大的矩形
* 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1
* 求在该柱状图中，能够勾勒出来的矩形的最大面积
* https://www.programmercarl.com/0084.%E6%9F%B1%E7%8A%B6%E5%9B%BE%E4%B8%AD%E6%9C%80%E5%A4%A7%E7%9A%84%E7%9F%A9%E5%BD%A2.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-13
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk; // 找左右两边第一个比当前元素小的元素 维护单调递减栈
        // 首位加0 这样才能保证首尾的元素在计算情况(3)时也有左侧与右侧元素，而不至于空栈导致无法计算
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        stk.push(0);
        int res = 0;
        for(int i = 1; i < heights.size(); i++) {
            if(heights[i] > heights[stk.top()]) {
                stk.push(i);
            } else if(heights[i] == heights[stk.top()]) {
                stk.pop();  // 这里不pop也可 其实就是多一次计算过程
                // 因为相等的时候 最大的宽度一定是相等的柱子数目加起来
                stk.push(i);
            } else {
                while (!stk.empty() && heights[i] < heights[stk.top()]) {
                    int mid = stk.top();
                    stk.pop();
                    if(!stk.empty()) {
                        int H = heights[mid];
                        // 只计算mid这个高度所能覆盖的 画个图看就清晰了
                        int W = i - stk.top() - 1;
                        res = max(res, H * W);
                    }
                }
                // 第一次忘记push当前元素进栈了
                stk.push(i);
            }
        }
        return res;
    }
};

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    Solution s;
    cout << s.largestRectangleArea(heights) << endl;
    return 0;
}
