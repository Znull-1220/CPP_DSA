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

