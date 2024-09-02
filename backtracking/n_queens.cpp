/**
* @file      n_queens.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #51. N皇后
* n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
* 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
* 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
* 输入：n = 4
* 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
* 解释：如上图所示，4 皇后问题存在两个不同的解法。
* https://www.programmercarl.com/0051.N%E7%9A%87%E5%90%8E.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-2
* @copyright Copyright (c) 2024
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<string>> res;

    bool isVaild(int row, int col, vector<string>& chessboard) {
        // 要求不同行，不同列，不同斜线
        for(int i = 0; i < row; i++) {
            if(chessboard[i][col] == 'Q') {
                return false;
            }
        }

        // 45度角不同斜线
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(chessboard[i][j] == 'Q') {
                return false;
            }
        }

        // 135度角不同斜线
        for(int i = row - 1, j = col + 1; i >= 0 && j < chessboard.size(); i--, j++) {
            if(chessboard[i][j] == 'Q') {
                return false;
            }
        }
        // 每行只有一个皇后 不用check行冲突
        return true;
    }

    void backtracking(int n, int row, vector<string>& chessboard) {
        // 递归终止条件 问题里行树就是树的最大深度
        if(n == row) {
            res.push_back(chessboard);  // 这里push的是每种合法的情况
            return;
        }

        // 只在列之间切换 每一次递归代表一行
        for(int col = 0; col < n; col++) {
            if(isVaild(row, col, chessboard)) {
                chessboard[row][col] = 'Q';
                backtracking(n, row + 1, chessboard);   // 下一行
                chessboard[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        vector<string> chessboard(n, string(n, '.'));  // 初始化棋盘 n*n 的'.'
        backtracking(n, 0, chessboard);
        return res;
    }
};

int main() {
    int n = 4;
    Solution s;
    vector<vector<string>> res = s.solveNQueens(n);
    for(auto i : res) {
        for(auto j : i) {
            cout << j << endl;
        }
        cout << endl;
    }
    return 0;
}
