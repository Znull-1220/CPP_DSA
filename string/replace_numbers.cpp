/**
* @file      replace_numbers.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     替换数字
* 给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。
* 例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"。
* 输入：一个字符串 s,s 仅包含小写字母和数字字符。
* https://www.programmercarl.com/kamacoder/0054.%E6%9B%BF%E6%8D%A2%E6%95%B0%E5%AD%97.html#%E6%80%9D%E8%B7%AF
* @date      24-8-18
* @copyright Copyright (c) 2024
*/


#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "a1b2c3";
    int oldIdx = s.size() - 1;
    // 双指针法，先进行空间扩充，预留空间
    int count = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            count++;
        }
    }

    s.resize(s.size() + count * 5);

    // 从后往前进行替换 双指针
    // 旧指针指向原字符串末尾，新指针指向新字符串末尾
    int newIdx = s.size() - 1;
    while(oldIdx >= 0) {
        if(s[oldIdx] >= '0' && s[oldIdx] <= '9') {
            s[newIdx--] = 'r';
            s[newIdx--] = 'e';
            s[newIdx--] = 'b';
            s[newIdx--] = 'm';
            s[newIdx--] = 'u';
            s[newIdx--] = 'n';
            oldIdx--;
        }
        else {
            s[newIdx--] = s[oldIdx--];
        }
    }

    cout << s << endl;
}