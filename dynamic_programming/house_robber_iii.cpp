/**
* @file      house_robber_iii.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #337. 打家劫舍 III  树形DP
* @date      24-9-11
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * 思路1 后续遍历 暴力递归
 * 如果不抢当前父节点 就可以考虑抢左右孩子
 */
class Solution1 {
public:
    unordered_map<TreeNode* , int> umap; // 记录计算过的结果
    int rob(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return root->val;
        if (umap[root]) return umap[root]; // 如果umap里已经有记录则直接返回
        // 偷父节点
        int val1 = root->val;
        if (root->left) val1 += rob(root->left->left) + rob(root->left->right); // 跳过root->left
        if (root->right) val1 += rob(root->right->left) + rob(root->right->right); // 跳过root->right
        // 不偷父节点
        int val2 = rob(root->left) + rob(root->right); // 考虑root的左右孩子
        umap[root] = max(val1, val2); // umap记录一下结果
        return max(val1, val2);
    }
};


class Solution2 {
public:
    int rob(TreeNode* root) {
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    }

    vector<int> robTree(TreeNode* root) {
        // 空节点 偷不偷都是0
        if(root == nullptr)     return {0, 0};
        // vector 返回的元素是2个元素的int vec idx = 0不偷；idx = 1偷
        vector<int> left = robTree(root->left);
        vector<int> right = robTree(root->right);
        // 偷该根节点的元素 那么就不能偷左右两个孩子
        int val1 = root->val + left[0] + right[0];
        // 不偷根节点 可以偷左右两个孩子(当然只是考虑偷，并不是必须要偷 所以要涉及到比较)
        int val2 = max(right[0], right[1]) + max(left[0], left[1]);

        return {val2, val1};
    }
};

void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    Solution1 s1;
    cout << s1.rob(root) << endl;

    Solution2 s2;
    cout << s2.rob(root) << endl;

    deleteTree(root);
    return 0;
}
// root = [3,2,3,null,3,null,1] LC上的样例是层序遍历