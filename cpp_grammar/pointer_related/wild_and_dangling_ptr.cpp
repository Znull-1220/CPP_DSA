/**
 * @file wild_and_dangling_ptr.cpp
 * @author Jinghui Zhang (zhangjh1220@gmail.com)
 * @brief 特殊指针: 野指针, 空指针, 悬挂指针.
 * @date 2024-05-29
 * 
 * @copyright Copyright (c) 2024
 */

#include<iostream>

int main() {
    /* 空指针指向内存中编号为0的空间, 用于初始化指针
       它指向的内存是不可以访问的(*p), 0-255是系统占用 */

    // 三种方式：0是int类型，NULL在g++下是一个宏定义，而nullptr是有类型的
    // C++11之后推荐使用nullptr, 因为它有类型, 可以进行类型检查
    int *p1 = nullptr;
    int *p2 = NULL;

    // 空指针可以取地址
    int **pp = &p1;


    /* 野指针，表示指针指向非法的内存空间 */
    int *p3 = (int *)0x12345678;
    //std::cout << "*p3 = " << *p3 << std::endl; // 野指针不能访问
    // 报Segmentation fault，读取访问权限冲突，就是这块内存还没申请还要访问


    /* 悬挂指针，指针指向的内存空间已经释放 */
    int *p4 = new int(10);
    std::cout << "*p4 = " << *p4 << std::endl; 
    // 释放指针指向的内存，但是指针还在，现在就是悬挂指针
    delete p4;
    std::cout << "*p4 = " << *p4 << std::endl; // 这时候*p4是不确定的
    
    // 释放后指针还在，有可能指向的内存后续被其他程序占用/OS回收
    // 因此delete后，指针要置为nullptr, 避免悬挂指针
    p4 = nullptr;
}
