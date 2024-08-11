/**
* @file      swap_nodes_in_pairs.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     两两交换链表中节点 refer: https://leetcode.cn/problems/swap-nodes-in-pairs/description/
* @date      24-8-11
* @copyright Copyright (c) 2024
*/


#include <iostream>

#include "LinkedList.h"



class Solution {
public:
    LinkedList::ListNode* swap_node_in_pairs(LinkedList::ListNode* head) {
        LinkedList::ListNode* dummyHead = new LinkedList::ListNode(0);
        dummyHead->next = head;

        LinkedList::ListNode* cur = dummyHead;

        while (cur->next != nullptr && cur->next->next != nullptr) {

            LinkedList::ListNode* tmp1 = cur->next;
            LinkedList::ListNode* tmp2 = cur->next->next->next;

            // 分析：cur在第一轮中始终是dummy head
            cur->next = cur->next->next;
            cur->next->next = tmp1;
            cur->next->next->next = tmp2;

            cur = cur->next->next;  // 移动两位
        }

        LinkedList::ListNode* newhead = dummyHead->next;
        delete dummyHead;
        dummyHead = nullptr;
        return newhead;
    }
};


int main() {
    LinkedList linkedList;
    linkedList.addAtTail(1);
    linkedList.addAtTail(2);
    linkedList.addAtTail(3);
    linkedList.addAtTail(4);
    linkedList.addAtTail(5);

    LinkedList::ListNode* head = linkedList.getHead();
    Solution solution;
    LinkedList::ListNode* newHead = solution.swap_node_in_pairs(head);

    linkedList.changeHead(newHead);
    linkedList.printLinkedList();

}