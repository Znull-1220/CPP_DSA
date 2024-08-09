/**
* @file      definition.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     链表定义
* @date      24-8-9
* @copyright Copyright (c) 2024
*/

struct ListNode {
    int val;
    ListNode *next;

    // 只有一个参数的构造函数存在类型转换，最好加explicit
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode() : val(0), next(nullptr) {}
};

int main() {
    auto head = new ListNode(1);    // auto自动推断类型

    ListNode* node1 = new ListNode();

    node1->val = 2;

    delete head;
    delete node1;

}
