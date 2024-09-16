/**
* @file      queue_using_stack.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     用栈实现队列
* @date      24-9-14
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
    stack<int> inStack;
    stack<int> outStack;    // 需要两个栈，一个用于入队，一个用于出队
    // enqueue stack, dequeue stack
public:
    MyQueue() {}
    void push(int x) {
        inStack.push(x);
    }
    /* 出队栈有元素那么第一个元素就是队头元素
     * 如果没有元素就将入队栈所有元素按出栈顺序push进出队栈 那么第一个元素就是队头*/
    int pop() {
        int rear;
        if(!outStack.empty()) {
            rear = outStack.top();
            outStack.pop();
        } else {
            while(!inStack.empty()) {
                int elem = inStack.top();
                inStack.pop();
                outStack.push(elem);
            }
            rear = outStack.top();
            outStack.pop();
        }

        return rear;
    }

    int front() {
        int rear = this->pop();
        outStack.push(rear);
        return rear;
    }

    bool isEmpty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.pop() << endl;
    cout << q.front() << endl;
    cout << q.isEmpty() << endl;
    return 0;
}