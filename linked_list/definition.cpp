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

/**
 * 原链表进行移除节点
 */
class LinkedList1 {
public:
    ListNode* remove_elements(ListNode* head, int val) {
        // 删除头结点
        while (head != nullptr && head->val == val) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }

        // 删除非头结点
        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr) {}
        if (cur->next->val ==val) {
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        else {
            cur = cur->next;
        }
        return head;
    }
};

/**
 * 设置额外的头结点 虚拟头结点 dummy head
 */
class LinkedList2 {
public:
    /**
     * @brief 移除链表中所有值为val的节点
     * 设置虚拟头结点就无需对头结点进行特殊处理
     * @param head 链表头结点
     * @param val 需要移除的值
     * @return 移除后的链表
     */
    ListNode* remove_element(ListNode* head, int val) {
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode* cur = dummy_head; // current node
        while(cur->next != nullptr) {
            if(cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else {
                cur = cur->next;
            }
        }

        // 处理后删除dummy head
        head = dummy_head->next;
        delete dummy_head;

        return head;
    }
};

int main() {
    auto head = new ListNode(1);    // auto自动推断类型

    ListNode* node1 = new ListNode();

    node1->val = 2;

    delete head;
    delete node1;

}
