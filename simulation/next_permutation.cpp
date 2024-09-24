/**
* @file      next_permutation.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #31. 下一个排列
* https://leetcode.cn/problems/next-permutation/description/
* @date      24-9-23
* @copyright Copyright (c) 2024
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        // 一定注意是nums[i] >= nums[i + 1] [1, 1]这个测试用例 需要让它最终i = -1 不执行交换
        while(i >= 0 && nums[i] >= nums[i + 1]) {
            i--;    // 找到i 使其为第一个小于右边元素的idx
        }
        // 这时候nums[i] 后面的元素一定都是降序排列
        // 找到后面的最小的 大于nums[i] 的元素
        // i >= 0 说明不是所有元素都降序排列
        if(i >= 0) {
            int j = nums.size() - 1;
            // 找到第一个大于nums[i]的元素 就行
            // 因为后面是降序排列所以nums[j]这时候一定是第一个大于nums[i]的元素
            while(j >= 0 && nums[j] <= nums[i]) {
                j--;    // 这里从后往前检测是最好的 如果从i + 1开始的话 可能是没有小于nums[i]的元素
            }
            swap(nums, i, j);
        }
        // 交换后idx = i 后面的顺序还是不变的 仍然是降序
        // 最小的字典顺序 后面需变为升序
        // 即使i = -1 也需要将整个数组变为升序 直接翻转即可
        reverse(nums, i + 1, nums.size() - 1);
    }

private:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    void reverse(vector<int>& nums, int start, int end) {
        for(; start < end; start++, end--) {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
        }
    }
};

int main() {
    vector<int> nums = {1,1};
    Solution s;
    s.nextPermutation(nums);
    for (const int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}