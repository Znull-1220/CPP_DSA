/**
 * @file pointer_definition.cpp
 * @author Jinghui Zhang (zhangjh1220@gmail.com)
 * @brief 指针基本定义.
 * @date 2024-05-29
 * 
 * @copyright Copyright (c) 2024
 */
#include<iostream>

using namespace std;

int main()
{
    int x = 10;
    int y = 20;
    int *p1 = &x;
    int *p2 = &y;
    cout << "x = " << x << ", y = " << y << endl;
    cout << "p1 = " << p1 << ", p2 = " << p2 << endl;
    // *p1 = 10, *p2 = 20 指针前面加*表示取指针指向的值, 解引用
    // 找到指针指向内存的数据
    cout << "*p1 = " << *p1 << ", *p2 = " << *p2 << endl;

    // 4个字节，32位系统，一个字节8位，4字节32位
    // 64位系统下，一个字节8位，8字节64位(所有指针都是8字节)
    cout << "sizeof(int *) = " << sizeof(int*) << endl; 

    return 0;
}