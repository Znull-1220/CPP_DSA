/**
* @file      LinkedList.h
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     单链表定义
* @date      24-8-10
* @copyright Copyright (c) 2024
*/


#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

class LinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(): val(), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };

    LinkedList() {
        _dummyHead = new ListNode(0);   // dummy head
        _size = 0;
    }

    /**
     * index从0开始, 错误返回-1.
     * @param index 索引
     * @return 该index处value
     */
    int get(int index) {
        if(index > _size - 1 || index < 0) {
            return -1;
        }

        ListNode* cur = _dummyHead->next;
        // 头结点这里不影响，因为下面不符合就直接return idx = 0的值
        for(int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }


    ListNode* getHead() {
        return _dummyHead->next;
    }

    void changeHead(ListNode* newHead) {
        _dummyHead->next = newHead;
    }


    void addAtHead(int val) {
        ListNode* newHead = new ListNode(val);
        newHead->next = _dummyHead->next;
        _dummyHead->next = newHead;
        _size++;
    }

    void addAtTail(int val) {
        ListNode* newTail = new ListNode(val);
        ListNode* cur = _dummyHead;

        // CAUTION: while loop will change the value of the condition variable
        // namely _size which I used formerly
        while (cur->next != nullptr) {
            cur = cur->next;
        }

        cur->next = newTail;
        _size++;
    }

    void addAtIndex(int index, int val) {
        if(index < 0 || index > _size) {
            return;
        }
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyHead;

        // 经过循环后，cur指向index前一个节点
        for(int i = 0; i < index; i++) {
            cur = cur->next;
        }

        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    void deleteAtIndex(int index) {
        if(index < 0 || index >= _size) {
            return;
        }
        ListNode* cur = _dummyHead;
        for(int i = 0; i < index; i++) {
            cur = cur->next;
        }
        ListNode* delNode = cur->next;
        cur->next = delNode->next;

        delete delNode;
        // del并非是释放指针而是释放所指的内存，必须要将指针置为nullptr否则会成为野指针
        delNode = nullptr;
        _size--;
    }

    void printLinkedList() {
        ListNode* cur = _dummyHead;
        while(cur->next != nullptr) {
            std::cout << cur->next->val << " ";
            cur = cur->next;
        }

        std::cout << std::endl;
    }

private:
    ListNode* _dummyHead;
    int  _size;
};

// 类的static field必须在类外初始化
//::ListNode* LinkedList::_dummyHead = nullptr;
//int LinkedList::_size = 0;
#endif //LINKEDLIST_H
