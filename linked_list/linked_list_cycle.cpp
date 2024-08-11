/**
* @file      linked_list_cycle.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     环形链表II 给定一个链表，返回链表开始入环的第一个节点。如果链表无环，则返回 null。
* 为了表示给定链表中的环，使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环
* 说明：不允许修改给定的链表
* refer: https://leetcode.cn/problems/linked-list-cycle-ii/description/
* @date      24-8-11
* @copyright Copyright (c) 2024
*/

#include "LinkedList.h"
#include <iostream>

class Solution {
public:
    LinkedList::ListNode* detectCycle(LinkedList::ListNode *head) {
        if(head == nullptr) {
            return nullptr;
        }

        // 定义快慢指针 fast每次走2, slow每次走1
        LinkedList::ListNode* fast = head;
        LinkedList::ListNode* slow = head;

        while(fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            // 如果有环，fast和slow一定会相遇, 因为每次差1
            if(fast == slow) {
                /*
                 * 假设前面的部分长度为a，环的长度为l，slow走了n步，那么fast走了2n步
                 * 相遇点的长度在入口处+c的位置，环剩余的长度是b = l - c
                 * 2(a + c) = a + k * (b + c) + c
                 * 至少多走一圈，那么假设k = 1： 2a + 2c = a + b + 2c => a = b
                 */
                // 所以，从head开始，和slow一起走，相遇的地方就是环的入口
                LinkedList::ListNode* cur = head;
                while(cur != slow) {
                    cur = cur->next;
                    slow = slow->next;
                }
                return cur;
            }
        }

        return nullptr;
    }
};


int main() {
    LinkedList linkedList;
    linkedList.addAtTail(1);
    linkedList.addAtTail(2);
    linkedList.addAtTail(3);
    linkedList.addAtTail(4);
    linkedList.addAtTail(5);
    linkedList.addAtTail(6);
    linkedList.addAtTail(7);
    linkedList.addAtTail(8);

    LinkedList::ListNode* head = linkedList.getHead();

    // 以第四个节点为entry 即idx = 3
    LinkedList::ListNode* entryNode = head->next->next->next;

    linkedList.addAtTail(entryNode);

    //linkedList.printLinkedList();

    Solution s;
    LinkedList::ListNode* enrtyDetected = s.detectCycle(head);

    std::cout << "entry node: " << enrtyDetected->val << std::endl;
}