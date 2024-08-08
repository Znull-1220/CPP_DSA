/**
* @file      sum_of_sub_array.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     refer to :https://kamacoder.com/problempage.php?pid=1070
*
* 给定一个整数数组 Array，请计算该数组在每个指定区间内元素的总和。
* 输入描述
* 第一行输入为整数数组 Array 的长度 n，
* 接下来 n 行，每行一个整数，表示数组的元素。随后的输入为需要计算总和的区间下标：a，b （b > = a），直至文件结束。
* @date      24-8-8
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

class Solution {
public:
    /**
     * 暴力解法
     */
    int sum_of_sub_array1(std::vector<int>& nums, int a, int b) {
        int sum = 0;
        for (int i = a; i <= b; i++) {
            sum += nums[i];
        }
        return sum;
    }


    /**
     *
     * @param n 数组长度
     * @param a 下标下界
     * @param b 上界 a <= b
     * @return 区间和
     */
    int sum_of_sub_array2(int n, int a, int b) {
        std::vector<int> nums(n, 0);
        std::vector<int> prefix_sum(n, 0);
        for (int i = 0; i < n; i++) {
            std::cin >> nums[i];
            if (i == 0) {
                prefix_sum[i] = nums[i];
            } else {
                prefix_sum[i] = prefix_sum[i - 1] + nums[i];
            }
        }
        /*
        * 前缀和解法
        * 前缀和的思想是重复利用计算过的子数组之和，从而降低区间查询需要累加计算的次数
        * 在涉及计算区间和的问题时非常有用
        */

        // 现在，prefix_sum[i] 表示数组 nums[0] 到 nums[i] 的和
        // [a, b]的和就是 prefix_sum[b] - prefix_sum[a - 1]
        return prefix_sum[b] - (a == 0 ? 0 : prefix_sum[a - 1]);
    }
};

int main() {
    int n;
    // 大量输入输出用scanf & printf 更快
    scanf("%d", &n);
    int a;
    int b;
    // while(scanf("%d", &a) != EOF) scanf 读取失败会返回EOF(-1),
    // 也可以~scanf("%d", &a)来判定, -1 取反是 0
    scanf("%d%d", &a, &b);
    Solution solution;
    int sum = solution.sum_of_sub_array2(n, a, b);
    printf("%d", sum);
}
