/**
* @file      next_greater_element_i.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     496.下一个更大元素 I
* 给你两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集
* 请你找出 nums1 中每个元素在 nums2 中的下一个比其大的值
* nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素
* 如果不存在，对应位置输出 -1
* https://www.programmercarl.com/0496.%E4%B8%8B%E4%B8%80%E4%B8%AA%E6%9B%B4%E5%A4%A7%E5%85%83%E7%B4%A0I.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-13
 * @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


/*
 * 暴力解法 这样在LC oj也是可以通过的
 */
class Solution2 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                if(nums1[i] == nums2[j]) {
                    for(int k = j; k < nums2.size(); k++) {
                        if (nums2[k] > nums1[i]) {
                            res[i] = nums2[k];
                            break;
                        }
                    }
                }
            }
        }

        return res;
    }
};

/*
 * 单调栈解法
 */
class Solution1 {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        stack<int> stk;
        unordered_map<int, int> umap;
        for(int i = 0; i < nums1.size(); i++) {
            umap[nums1[i]] = i; // umap的key-value 为nums1中元素-元素下标
        }
        stk.push(0);
        for(int i = 1; i < nums2.size(); i++) {
            if (nums2[i] < nums2[stk.top()]) {
                stk.push(i);
            } else if (nums2[i] == nums2[stk.top()]) {
                stk.push(i);
            } else {
                while (!stk.empty() && nums2[i] > nums2[stk.top()]) {
                    // 如果有这个元素
                    if(umap.find(nums2[stk.top()]) != umap.end()) {
                        int index = umap[nums2[stk.top()]];
                        res[index] = nums2[i];
                    }
                    // 如果没这个元素 那么可以直接让它出栈 如果放在if里面出栈会直接死循环 根本执行不到
                    stk.pop();
                }
                stk.push(i);
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    Solution1 s;
    vector<int> res = s.nextGreaterElement(nums1, nums2);
    for(auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}