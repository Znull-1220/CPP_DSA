# Stack and Queue
## Overview
### Stack
栈是容器适配器，底层容器使用不同的容器，导致栈内数据在内存中不一定是连续分布的。缺省情况下，默认底层容器是deque，
deque在内存中是不连续的块，并不是和vector一样连续的内存块。
### Queue
队列，值得一提的有优先队列和单调队列。
#### 单调队列
单调队列指队列元素从对头到队尾单调。参阅[OI Wiki-单调队列](https://oi-wiki.org/ds/monotonous-queue/), 单调队列STL没有提供，自己实现一般用deque就可以了。
#### 优先队列
优先队列是一个堆实现的数据结构，堆实际就是完全二叉树，分为大根堆和小根堆。
- 大根堆：根节点的值最大，每个节点的值都大于等于其子节点的值。
- 小根堆：根节点的值最小，每个节点的值都小于等于其子节点的值。
      
优先队列可以指定容器为deque, vector等，比较函数也可以进行运算符重载，自定义比较函数。默认情况下，优先队列是大根堆(比较函数为less), 也可以指定为
小根堆(比较函数为greater)。

STL中的比较器类`greater<var_type>()`和`less<var_type>()`可以用于简单类型比较，比较func缺省时为`less<var_type>()`，但优先队列是比较反常的。
比较器类在**返回为TRUE**时不会交换两个变量的值，例如`sort`缺省时 使用`less`，在$lhs < rhs$下为*true*则不交换，所以默认下是从小到大排序，即升序。

大部分STL容器都是默认升序排序，而优先队列和map set sort等STL不一样，默认情况下`less`是维护一个大根堆，即大的元素在队头。
```c++
template<class T> struct greater
{
    // 这里其实是重载了()运算符，因此在使用的时候可以像函数一样调用
    bool operator()(const T& lhs, const T& rhs) const
    {
        return lhs > rhs;
    }
};
```
堆中插入新节点时是插入在最后一个叶子节点的位置。这里的`lhs`代表新插入的元素，`rhs`代表新插入元素的父节点。这里使用 > 说明期望子节点大于父节点，说明维护的是小根堆。

对于复杂数据类型的比较，可以采用重载运算符的方法——比较器类，aka 伪函数 

通过重载()运算符实现，重载()运算符的类叫做函数对象，函数对象是一个类或结构体

一个不错的动画形象理解：[【从堆的定义到优先队列、堆排序】](https://www.bilibili.com/video/BV1AF411G7cA/?spm_id_from=333.337.search-card.all.click&vd_source=ef9de71875848cf80f6a976318c7c534)


## 题目
### 互相实现
- [用栈实现队列](queue_using_stack.cpp)
- [用队列实现栈](stack_using_queue.cpp)
### Stack相关
- [LC #70.简化路径](simplify_path.cpp): 其实就是栈的一种应用，在词法分析中处理括号，也会用到stack这种数据结构。
- [LC #20.有效的括号](valid_parentheses.cpp)
- [LC #1047.删除字符串中的所有相邻重复项](remove_all_adjacent_duplicates_in_string.cpp): 就像消消乐一样，用栈来解决
- [LC #150.逆波兰表达式求值](evaluate_reverse_polish_notation.cpp)
### Queue相关
- [LC #239.滑动窗口最大值](sliding_window_maximum.cpp): 这是一道单调队列的经典题目
- [LC #347.前 K 个高频元素](top_k_frequent_elements.cpp): 这是一道典型的用优先队列来解决的题目。STL中提供了优先队列的实现`priority_queue`，
这里需要用小根堆，因为如果用大根堆的话频率最高的元素就变成了根节点，每次添加元素最大的元素都会被弹出，所以这里维护一个K大小的小根堆就可以了
