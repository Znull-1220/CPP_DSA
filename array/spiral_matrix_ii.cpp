/**
* @file      spiral_matrix_ii.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     Leetcode59 螺旋矩阵II ref: https://leetcode-cn.com/problems/spiral-matrix-ii/
* 给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix
* 模拟题，关键就是保持循环不变量，设置好边界条件
* @date      24-8-8
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate_matrix(int n) {
        std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
        int startX = 0, startY = 0;
        int loop = n / 2;
        int i, j;
        int count = 1;  // 用于赋值
        int offset = 1;

        while (loop--) {
            // 使用[i, j) 左开右闭
            // 采用X为横坐标，Y为纵坐标，这时(i, j)表示第i行第j列
            // 但是vec [i][j] 这里要移动横坐标应该变化列，也就是变化j
            i = startX;
            j = startY;

            // 注意是j
            for(; j < n - offset; j++) {
                res[i][j] = count++;
            }
            for(; i < n - offset; i++) {
                res[i][j] = count++;
            }
            for(; j > startX; j--) {
                res[i][j] = count++;
            }
            for(; i > startY; i--) {
                res[i][j] = count++;
            }

            offset++;
            startX++;
            startY++;
        }

        if(n % 2 == 1) {
            res[startX][startY] = count;
        }

        return res;
    }


};

int main() {
    Solution s;
    std::vector<std::vector<int>> res = s.generate_matrix(3);
    for (std::vector<int>row : res) {
        for(int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}