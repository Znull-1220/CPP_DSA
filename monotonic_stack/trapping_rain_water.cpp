/**
* @file      trapping_rain_water.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #42. 接雨水
* https://www.programmercarl.com/0042.%E6%8E%A5%E9%9B%A8%E6%B0%B4.html#%E6%80%9D%E8%B7%AF
* @date      24-9-13
* @copyright Copyright (c) 2024
*/

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

/*
 * 解法1 双指针优化 提前存储每个位置左右最大高度
 * 这是对每一列去计算的 就是将每个位置视为一列 宽度为1 纵向累计
 */
class Solution1 {
public:
    int trap(vector<int>& height) {
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        // 记录每个柱 左边柱子最大高度
        maxLeft[0] = height[0];
        for(int i = 1; i < height.size(); i++) {
            // 迭代过去 最大的会一直保持
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        }
        maxRight[height.size() - 1] = height[height.size() - 1];
        for(int i = height.size() - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], height[i]);
        }

        int res = 0;
        for(int i = 0; i < height.size(); i++) {
            // 最小的高度减去当前高度就是当前位置的容量
            int capacity = min(maxLeft[i], maxRight[i]) - height[i];
            if(capacity > 0)    res += capacity;
        }

        return res;
    }
};

/*
 * 解法2 单调栈
 * 这种方法是横向去计算的 e.g. 2,1,0,0,3 那么就是先1—3这一片区域的水量 然后2—3这一片区域的水量(这时候最低的是2)
 * 还是维护单调递增栈
 */
class Solution2 {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        stk.push(0);
        int sum = 0;
        for(int i = 1; i < height.size(); i++) {
            if(height[i] < height[stk.top()]) {
                stk.push(i);
            } else if (height[i] == height[stk.top()]) {
                // 相等的时候 更新下标 因为相等的时候需要用最右边的下标去计算
                stk.pop();
                stk.push(i);
            } else {
                while(!stk.empty() && height[i] > height[stk.top()]) {
                    int mid = height[stk.top()];
                    stk.pop();
                    if(!stk.empty()) {
                        // 第一次忘记减去mid了
                        int H = min(height[i], height[stk.top()]) - mid;
                        // 注意只算中间部分 画一个2，1，0，0,3的图 就很清晰了
                        int W = i - stk.top() - 1;
                        sum += H * W;
                    }
                }
                stk.push(i);
            }
        }
        return sum;
    }
};

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution1 sl1;
    cout << sl1.trap(height) << endl;
    Solution2 sl2;
    cout << sl2.trap(height) << endl;
    return 0;
}