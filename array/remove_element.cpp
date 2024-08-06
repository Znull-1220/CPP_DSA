/**
* @file      remove_element.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     移除元素(LeetCode 27): 给你一个数组 nums 和一个值 val
* @date      24-7-29
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

/**
 * 暴力解法
 */
class Solution1 {
public:
    static int removeElement(std::vector<int>& nums, int val) {
        int size = static_cast<int>(nums.size());
        int temp = 0;
        for(int i = 0; i < size; i++){
            if(nums[i] == val){
                for(int j = i + 1; j < size; j++){
                    nums[j - 1] = nums[j];
                }
                size--;
                i--;  // i前移一位, 因为后面的元素移动到了当前位置上
            }
        }
        return size;

    }
};

/**
 * 双指针解法
* 定义快慢指针
* 快指针：寻找新数组的元素 ，新数组就是不含有目标元素的数组
* 慢指针：指向更新 新数组下标的位置
 */
class Solution2 {
public:
    static int removeElement(std::vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

int main(){
    std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    std::vector<int> nums1(nums);
    int val = 2;

    int res1 = Solution1::removeElement(nums, val);
    std::cout << res1 << std::endl;
    Solution2 s2;
    int res2 = s2.removeElement(nums1, val);
    std::cout << res2 << std::endl;
    return 0;
}