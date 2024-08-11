/**
* @file      intersection_of_two_linked_lists.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     链表相交 给你两个单链表的头节点 headA 和 headB
* 找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null
* https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
* @date      24-8-11
* @copyright Copyright (c) 2024
*/

#include "LinkedList.h"
#include <iostream>

class Solution {
public:
    LinkedList::ListNode* getIntersectionNode(LinkedList::ListNode* headA, LinkedList::ListNode* headB) {
        if(headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        LinkedList::ListNode* curA = headA;
        LinkedList::ListNode* curB = headB;
        int lenA = 0;
        int lenB = 0;

        // 获取A B 链表长度
        while(curA) {
            curA = curA->next;
            lenA++;
        }

        while(curB) {
            curB = curB->next;
            lenB++;
        }

        // 始终让A成为较长的链表
        if(lenA < lenB) {
            std::swap(lenA, lenB);
            std::swap(headA, headB);
        }

        int offset = lenA - lenB;   // 两链表差值

        // 让A的指针先走offset步，末尾对齐
        // 因为最后一段节点是共享的，所以相交的节点一定与前面长度不相同的这一部分node无关
        curA = headA;
        curB = headB;
        while(offset--) {
            curA = curA->next;
        }

        while(curA != nullptr) {
            if(curA == curB) {
                return curA;
            }

            curA = curA->next;
            curB = curB->next;
        }

        return nullptr;
    }

};

int main() {
    LinkedList linkedList1;
    linkedList1.addAtTail(1);
    linkedList1.addAtTail(2);
    linkedList1.addAtTail(3);
    linkedList1.addAtTail(4);
    linkedList1.addAtTail(5);

    LinkedList linkedList2;
    linkedList2.addAtTail(6);
    linkedList2.addAtTail(7);

    // 交点
    LinkedList::ListNode* insectionNode = new LinkedList::ListNode(8);

    linkedList1.addAtTail(insectionNode);
    linkedList2.addAtTail(insectionNode);

    // 这一部分两个链表共享
    linkedList1.addAtTail(9);
    linkedList1.addAtTail(10);
    linkedList1.addAtTail(11);

    std::cout << "LinkedList1: ";
    linkedList1.printLinkedList();
    std::cout << "LinkedList2: ";
    linkedList2.printLinkedList();

    Solution solution;
    LinkedList::ListNode* insection = solution.getIntersectionNode(linkedList1.getHead(), linkedList2.getHead());

    std::cout << "The value of intersection node: " << insection->val << std::endl;
}
