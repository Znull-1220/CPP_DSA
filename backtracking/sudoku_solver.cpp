/**
* @file      sudoku_solver.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #37. 解数独 hard
* 数独的解法需 遵循如下规则
* 数字 1-9 在每一行只能出现一次。
* 数字 1-9 在每一列只能出现一次。
* 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
* 数独部分空格内已填入了数字，空白格用 '.' 表示
* https://www.programmercarl.com/0037.%E8%A7%A3%E6%95%B0%E7%8B%AC.html#%E6%80%9D%E8%B7%AF
* @date      24-9-2
* @copyright Copyright (c) 2024
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    bool isValid(char k, int row, int col, vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            // 是否同行或同列有重复
            if(board[row][i] == k || board[i][col] == k) {
                return false;
            }
            // 是否同一个3*3宫内有重复
            int startRow = 3 * (row / 3);   // 3 * 0, 3 * 1, 3 * 2
            int startCol = 3 * (col / 3);
            for(int i = startRow; i < startRow + 3; i++) {
                for(int j = startCol; j < startCol + 3; j++) {
                    if(board[i][j] == k) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    // 不需要result来收集了 找到一个就OK，而且也是直接在board上用引用做的
    bool backtracking(vector<vector<char>>& board) {
        // 填满自然就终止 不需要终止条件
        // 二维递归，一个遍历行 一个遍历列;
        // 我的理解就是对每一个位置不断尝试 每一个位置都是一棵树 所以不需要传入row/col
        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board[0].size(); col++) {
                if(board[row][col] != '.') {    // 如果是数字就跳过
                    continue;
                }
                for(char k = '1'; k <= '9'; k++) {
                    if(isValid(k, row, col, board)) {
                        board[row][col] = k;
                        if(backtracking(board)) {
                            return true;    // 找到一个就返回
                        }
                        board[row][col] = '.';  // 回溯
                    }
                }

                return false;   // 没有找到 不会死循环的关键 9个数字都试过了 都不行
            }
        }

        return true; // 遍历完没有返回false，说明找到了合适棋盘位置了
        // 这个不能漏，不然会编译错误，虽然对结果没影响但必须每个分支都有返回值
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    Solution s;
    s.solveSudoku(board);
    for(auto i : board) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
