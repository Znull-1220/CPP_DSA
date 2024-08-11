/**
* @file      remove_nth_node_from_end_of_list.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     删除链表的倒数第 N 个结点 https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
* @date      24-8-11
* @copyright Copyright (c) 2024
*/

#include "LinkedList.h"
#include <iostream>


class Solution {
public:
    LinkedList::ListNode* remove(LinkedList::ListNode* head, int n) {
        LinkedList::ListNode* dummyHead = new LinkedList::ListNode(0);
        dummyHead->next = head;

        LinkedList::ListNode* slow = dummyHead;
        LinkedList::ListNode* fast = dummyHead;

        // 让fast指针先走n+1步
        n++;

        while(n--) {
            fast = fast->next;
        }

        // 这时让fast指针走到最后一个节点，slow指针就是倒数第n+1个节点，就是要移除的node的前一个node
        // 最终让fast指向末尾nullptr
        while(fast !=  nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        LinkedList::ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        delNode = nullptr;

        auto newHead = dummyHead->next;

        delete dummyHead;
        dummyHead = nullptr;

        return newHead;
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
    LinkedList::ListNode* head = solution.remove(linkedList.getHead(), 2);
    linkedList.changeHead(head);
    linkedList.printLinkedList();
}