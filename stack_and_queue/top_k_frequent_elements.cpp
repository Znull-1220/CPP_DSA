/**
* @file      top_k_frequent_elements.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     347.前 K 个高频元素
* https://www.programmercarl.com/0347.%E5%89%8DK%E4%B8%AA%E9%AB%98%E9%A2%91%E5%85%83%E7%B4%A0.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-15
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    class comparison{
    public:
        // 伪函数 重载()运算符 重载()运算符的类叫做函数对象 函数对象是一个类或结构体
        // lhs: left hand side 左操作数 rhs: right hand side 右操作数
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
            // 默认less是大顶堆 -> greater是小顶堆
            // 小顶堆 元素大于 这和sort相反 就是元素大需要下沉
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;   // key: nums[i] value: count
        for(int i = 0; i < nums.size(); i++) {
            umap[nums[i]]++;
        }
        // 小顶堆 优先级队列的实现其实就是堆
        // std::priority_queue<type, container, comparison> pri_que;
        // 容器默认是vector, comparison默认是less<type> 大顶堆 容器一般是vector或deque
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparison> pri_que;
        for(auto & it : umap) {
            pri_que.push(it);
            if(pri_que.size() > k)      pri_que.pop();
        }

        // 小顶堆 所以每次弹出的都是较小的元素
        vector<int> res;
        while(!pri_que.empty()) {
            res.push_back(pri_que.top().first);
            pri_que.pop();
        }
        return res;
    }
};


int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    Solution s;
    vector<int> res = s.topKFrequent(nums, 2);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}