/**
* @file      4sum.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     第18题. 四数之和
* 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target
* 请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]]
* （若两个四元组元素一一对应，则认为两个四元组重复）：
* 0 <= a, b, c, d < n  a、b、c 和 d 互不相同
* nums[a] + nums[b] + nums[c] + nums[d] == target
*
* 示例 1：
* 输入：nums = [1,0,-1,0,-2,2], target = 0
* 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
* https://leetcode.cn/problems/4sum/description/
* @date      24-8-15
* @copyright Copyright (c) 2024
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        // 双指针法一定要记得排序，因为双指针法的前提是有序
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            // pruning 因为如果多个负数大于target相加是有可能满足条件的，但是正数不可能满足
            if(nums[i] >= 0 && nums[i] > target) {
                break;
            }
            // 去重nums[i] 也就是a 这里和3数字相加的逻辑一样，也是和前面的数字比较，这样不会遗漏重复的元素
            // 注意i > 0 当前i最小是1才能和前面比较
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            // pruning逻辑和第一层完全一样，可以从这里推广到n数之和，就是n-2层循环最后一层双指针
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] >= 0 && nums[i] + nums[j] > target) {
                    break;
                }

                if(j > i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }

                // 双指针
                int left = j + 1;
                int right = static_cast<int>(nums.size()) - 1;

                // 查找b c 注意这里是个循环
                while(left < right) {
                    if(nums[i] + nums[j] + nums[left] + nums[right] > target) {
                        right--;
                    } else if(static_cast<long>(nums[i] + nums[j] + nums[left] + nums[right] < target)) {
                        left++;
                    } else {
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});

                        // 去重c d 注意用while一次完成去重 并且控制left < right(自己写的时候忘记这个条件了)
                        while (right > left && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        while (right > left && nums[right] == nums[right - 1]) {
                            right--;
                        }

                        // 找到答案后，双指针同时收缩
                        left++;
                        right--;
                    }
                }
            }
        }

        return result;
    }
};


int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution solution;
    vector<vector<int>> result = solution.fourSum(nums, target);
    for(auto& item : result) {
        for(auto& i : item) {
            cout << i << " ";
        }
        cout << endl;
    }
}
