/**
* @file      sliding_window_maximum.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #239. 滑动窗口最大值
* https://www.programmercarl.com/0239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-15
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
private:
    // 单调队列 因为求的是最大值，所以队列中的元素是单调递减的(from front to rear)
    class MonotonicQueue {
    public:
        MonotonicQueue() {}
        deque<int> que;
        void pop(int val) {
            // 记得判断是否为空
            // 当前值等于队列头部元素时，弹出头部元素
            if(!que.empty() && val == que.front())  que.pop_front();
        }
        void push(int val) {
            while(!que.empty() && que.back() < val) {
                que.pop_back();     // 弹出队列尾部元素
                // NOTICE 这里不能用if写在里面 因为遇到小于等于的元素就会直接死循环
                // Debug的时候直接没有frame和variable了
                // if(que.back() < val) {
                //     que.pop_back();     // 弹出队列尾部元素
                // }
            }
            que.push_back(val);
        }
        int front() {
            // 队头元素就是当前窗口的最大值
            return  que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue que;
        vector<int> res;
        for(int i = 0; i < k; i++) {
            que.push(nums[i]);  // 先将前k个元素放入队列 那么此时队头元素就是当前窗口的最大值
        }
        res.push_back(que.front());
        for(int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);  // 弹出窗口最左边的元素
            que.push(nums[i]);      // 将新元素放入队列
            res.push_back(que.front()); // 队头元素就是当前窗口的最大值
        }

        return res;
    }
};


int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    Solution s;
    vector<int> res = s.maxSlidingWindow(nums, k);
    for(auto r : res) {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}
