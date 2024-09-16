/**
* @file      stack_using_queue.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     用队列实现栈
* @date      24-9-15
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <queue>

using namespace std;

class MyStack {
    queue<int> q1;
    queue<int> q2;  // q2用于辅助q1 备用队列
    /*
     * 这是两个队列的实现方法
     * 如果使用一个队列 那么pop时候将除了最后一个元素外的所有元素都pop出来并重新加入队列 就可以实现栈的FILO
     */
public:
    void push(int x) {
        q1.push(x);
    }
    int pop() {
        int size = q1.size();
        size--;
        // 把q1的元素依次放入q2中 只留下最后一个元素 stack是FILO的
        while(size--) {
            q2.push(q1.front());
            q1.pop();
        }
        int elem = q1.front();
        q1.pop();
        // 交换q1和q2  重新把元素放回q1
        swap(q1, q2);

        return elem;
    }
    int top() {
        return q1.back();
    }
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.empty() << endl;
    return 0;
}
