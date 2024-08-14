/**
* @file      4sum_ii.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     第454题.四数相加II Medium
* 给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0
* 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500
* 所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过 2^31 - 1
* @date      24-8-13
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> ab_sum_map; // key: A[i] + B[j], value: key值出现次数
        for(int num1 : nums1) {
            for(int num2 : nums2) {
                ab_sum_map[num1 + num2]++;
            }
        }

        int count = 0;

        // 这样双层for是单独统计每一种组合
        for(int num3 : nums3) {
            for(int num4 :nums4) {
                // 判断iter
                if(ab_sum_map.find(-num3 - num4) != ab_sum_map.end()) {
                    count += ab_sum_map[-num3 - num4];
                }
            }
        }

        return count;
    }
};


int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};
    Solution solution;
    cout << solution.fourSumCount(nums1, nums2, nums3, nums4) << endl;
    return 0;
}

/*
 * 一道典型的hash table题目, 因为是四个数组所以要分成两组, 两两组合
 */
