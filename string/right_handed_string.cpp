/**
* @file      right_handed_string.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     右旋字符串
* 字符串的右旋转操作是把字符串尾部的若干个字符转移到字符串的前面。
* 例如，对于输入字符串 "abcdefg" 和整数 2，函数应该将其转换为 "fgabcde"。
* 输入：输入共包含两行，第一行为一个正整数 k，代表右旋转的位数。第二行为字符串 s，代表需要旋转的字符串。
* https://www.programmercarl.com/kamacoder/0055.%E5%8F%B3%E6%97%8B%E5%AD%97%E7%AC%A6%E4%B8%B2.html#%E6%80%9D%E8%B7%AF
* @date      24-8-18
* @copyright Copyright (c) 2024
*/


#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int k = 2;
    string s = "abcdefg";
    // 不申请新空间，在本字符串操作

    // 其实思路和之前的都差不多，整体反转+局部反转，比如说可以先整体翻转，再把后面n - k做局部翻转,再把前面k做局部翻转
    reverse(s.begin(), s.end());
    // +k 刚好指向第 k + 1 个元素 即为需要翻转的第一个
    reverse(s.begin() + k, s.end());
    reverse(s.begin(), s.begin() + k);
    cout << s << endl;
}