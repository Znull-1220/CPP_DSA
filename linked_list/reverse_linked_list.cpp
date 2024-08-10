/**
* @file      reverse_linked_list.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     翻转链表 refer: https://leetcode.cn/problems/reverse-linked-list/description/
* @date      24-8-10
* @copyright Copyright (c) 2024
*/

#include "LinkedList.h"

#include <iostream>

class Solution {
    // 双指针法
    LinkedList::ListNode* reverseList(LinkedList::ListNode* head) {
        LinkedList::ListNode* prev = nullptr;
        LinkedList::ListNode* cur = head;
        while (cur) {
            LinkedList::ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};


int main() {
    LinkedList linkedList;
    linkedList.addAtHead(1);
    linkedList.addAtHead(2);
    linkedList.addAtHead(3);
    linkedList.addAtHead(4);
    linkedList.addAtHead(5);
    linkedList.printLinkedList();
    // static function用对象无法直接访问？？？ TODO

}