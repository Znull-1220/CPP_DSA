/**
* @file      word_ladder.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     卡码网（ACM模式） 110. 字符串接龙
* 题目描述
* 字典 strList 中从字符串 beginStr 和 endStr 的转换序列是一个按下述规格形成的序列：序列中第一个字符串
* 是 beginStr；序列中最后一个字符串是 endStr。
* 每次转换只能改变一个字符。
* 转换过程中的中间字符串必须是字典 strList 中的字符串。
* 给你两个字符串 beginStr 和 endStr 和一个字典 strList，找到从 beginStr 到 endStr的最短转换序列中
* 的字符串数目。如果不存在这样的转换序列，返回 0。
* 输入描述
* 第一行包含一个整数 N，表示字典 strList 中的字符串数量。 第二行包含两个字符串，用空格隔开，
* 分别代表 beginStr 和 endStr。 后续 N 行，每行一个字符串，代表 strList 中的字符串。
* 输出描述
* 输出一个整数，代表从 beginStr 转换到 endStr 需要的最短转换序列中的字符串数量。如果不存在这样的转换
* 序列，则输出 0。
* https://www.programmercarl.com/kamacoder/0110.%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%8E%A5%E9%BE%99.html#%E6%80%9D%E8%B7%AF
* AND LC #127. Word Ladder https://leetcode.cn/problems/word-ladder/description/ (Hard)
* @date      24-9-6
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

/*
 * 这道题DFS会很耗时 因为要搜最短路径
 * 使用BFS是最好的，因为BFS是逐层遍历的，搜到一定是最短路径
 */
int main() {
    int n;
    cin >> n;
    string beginStr, endStr;
    cin >> beginStr >> endStr;
    // 用set存储字典 这样查找是否存在的时候更快
    unordered_set<string> strList;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        strList.insert(str);
    }
    queue<string> que;
    que.push(beginStr);
    unordered_map<string, int> pathMap;    // 字符串, 当前路径长度
    pathMap.insert(pair<string, int>(beginStr, 1));

    while(!que.empty()) {
        string curStr = que.front();
        que.pop();
        int path = pathMap[curStr];

        for(int i = 0; i < curStr.size(); i++) {
            string newStr = curStr;
            // 枚举每一位的26种可能
            for(int j = 0; j < 26; j++) {
                newStr[i] = 'a' + j;
                // 如果切换一位等于结果字符串
                if(newStr == endStr) {
                    cout << path + 1 << endl;
                    return 0;
                }

                // 如果新字符串在字典中存在 且没有被访问过
                // 如果不判断是否访问过 会造成重复访问->死循环
                if(pathMap.find(newStr) == pathMap.end() &&
                    strList.find(newStr) != strList.end()) {
                    que.push(newStr);
                    pathMap.insert(pair<string, int>(newStr, path + 1));
                }
            }
        }
    }

    cout << 0 << endl;
    return 0;
}
