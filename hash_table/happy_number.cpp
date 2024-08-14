/**
* @file      happy_number.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     Leetcode #202.快乐数
* 「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，
* 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为 1，那么这个数就是快乐数。
* 如果 n 是快乐数就返回 True ；不是，则返回 False
* https://leetcode.cn/problems/happy-number/description/
* @date      24-8-13
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <unordered_set>

class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while(n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }

        return sum;
    }


    bool isHappy(int n) {
        std::unordered_set<int> set;

        while(true) {
            int sum = getSum(n);

            if(sum == 1) {
                return true;
            }

            if(set.find(sum) != set.end()) {
                return false;
            }
            // 加入set记录
            // 题目关键就是：可能出现无限循环说明 数字会有重复，那么在重复时就可以判断为FALSE
            else {
                set.insert(sum);
                n = sum;
            }
        }

    }
};


int main() {
    Solution s;
    std::cout << s.isHappy(19) << std::endl;
    std::cout << s.isHappy(2) << std::endl;
}