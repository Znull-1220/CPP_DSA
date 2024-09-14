/**
* @file      daily_temperatures.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #739. 每日温度
* 请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数
* 如果气温在这之后都不会升高，请在该位置用 0 来代替。
* 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
* 你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
* 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数
* https://www.programmercarl.com/0739.%E6%AF%8F%E6%97%A5%E6%B8%A9%E5%BA%A6.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-13
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        stack<int> stk;
        stk.push(0);
        // 顺序的描述为 从栈头到栈底的顺序，这里需要维护一个单调递增的栈
        for(int i = 1; i < temperatures.size(); i++) {
            if (temperatures[i] > temperatures[stk.top()]) {
                while(!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                    answer[stk.top()] = i - stk.top();
                    stk.pop();
                }
                // 注意是循环结束后才将i入栈 不然进入下一轮循环 stk.top()就变成i了
                stk.push(i);
                //  其余两种情况 temperatures[i] <= temperatures[stk.top()] 直接入栈
            } else {
                stk.push(i);
            }
        }

        return answer;
    }
};

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution s;
    vector<int> answer = s.dailyTemperatures(temperatures);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}