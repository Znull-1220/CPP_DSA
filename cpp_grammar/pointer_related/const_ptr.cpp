/**
 * @file const_ptr.cpp
 * @author Jinghui Zhang (zhangjh1220@gmail.com)
 * @brief const修饰指针
 * @date 2024-05-29
 * 
 * @copyright Copyright (c) 2024
 */

using namespace std;

int main() {
    /* 
    const修饰指针 —— 常量指针 指针指向可以改，指针指向的值不可以改
    const修饰常量 —— 指针常量 指针指向不可以改，指针指向的值可以改
    const既修饰指针又修饰常量 —— 常量指针常量 指针指向和指针指向的值都不可以改
    */

    int a = 10;
    int b = 20;
    int *p1 = &a;
    // 常量指针 const int*
    const int * p2 = &a;
    //*p2 = 100;  error 表达式必须是可修改的左值C/C++(137)
    p2 = &b; // ok


    // 指针常量 const p3
    int * const p3 = &a;


    // 常量指针常量 const int * const 均不可以改
    const int * const p4 = &a;

    return 0;
}