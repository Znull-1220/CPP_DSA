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
public:
    // 双指针法
    LinkedList::ListNode* reverseList(LinkedList::ListNode* head) {
        LinkedList::ListNode* prev = nullptr;
        LinkedList::ListNode* cur = head;
        LinkedList::ListNode* tmp = cur->next;

        while (cur) {
            // prev作为前一个指针，cur作为当前指针
            // 先移动prev指针，再移动cur指针
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;

        }
        return prev;
    }

    /**
     * 递归处理，通常是从前往后处理，和双指针一样；这一思路是从后往前处理.
     * 这涉及到回溯的过程，“每次递归调用都会在栈上保存当前函数的执行状态，当递归到达基准条件（即链表的末尾）时，函数开始逐层返回，恢复之前保存的状态。这就是回溯。”
     * 所以最后会逐层回复原来的操作以完成翻转，e.g. 1->2->3->4->5->NULL 最后会从4—>3->2->1这样来回溯
     */
    LinkedList::ListNode* reverseList2(LinkedList::ListNode* head) {
        // 边缘条件判断
        if(head == nullptr) return nullptr;
        if (head->next == nullptr) return head;

        // 递归调用，翻转第二个节点开始往后的链表
        LinkedList::ListNode *last = reverseList2(head->next);
        // 压栈后现在是倒数第二个节点为head，倒数第一个节点为head->next
        head->next->next = head;
        // 此时的 head 节点为尾节点，next 需要指向 NULL
        head->next = nullptr;
        return last;
    }
};


int main() {
    LinkedList linkedList;
    linkedList.addAtTail(1);
    linkedList.addAtTail(2);
    linkedList.addAtTail(3);
    linkedList.addAtTail(4);
    linkedList.addAtTail(5);
    linkedList.printLinkedList();

    Solution solution;
    LinkedList::ListNode* head = solution.reverseList(linkedList.getHead());
    linkedList.changeHead(head);
    linkedList.printLinkedList();

    head = solution.reverseList2(linkedList.getHead());
    linkedList.changeHead(head);
    linkedList.printLinkedList();

}