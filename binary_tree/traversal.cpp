/**
* @file      traversal.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     二叉树前序、中序、后序遍历(递归遍历，深度优先DFS)
* 递归遍历的原理是用栈处理
* @date      24-8-20
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Traversal {
public:
    // 确定参数和返回值, root 以及一个vector保存遍历结果
    /**
     * @brief 二叉树前序遍历
     * 顺序其实就是根节点的位置
     */
    void preTraversal(TreeNode* root, vector<int>& res) {
        TreeNode* cur = root;
        // 边界条件：当前节点为空那么递归结束
        if (cur == nullptr) return;
        // 前序遍历 (Preorder Traversal): D(Data) -> L -> R
        res.push_back(cur->val);           // 中
        preTraversal(cur->left, res);   // 左
        preTraversal(cur->right, res);  // 右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preTraversal(root, result);
        return result;
    }

    /**
     * @brief 二叉树中序遍历
     */
    void inOrderTraversal(TreeNode* root, vector<int>& res) {
        TreeNode* cur = root;
        if (cur == nullptr) return;
        // 中序遍历 (Inorder Traversal): L -> D -> R
        inOrderTraversal(cur->left, res);
        res.push_back(cur->val);
        inOrderTraversal(cur->right, res);
    }

    void postOrderTraversal(TreeNode* root, vector<int>& res) {
        TreeNode* cur = root;
        if (cur == nullptr) return;
        // 后序遍历 (Postorder Traversal): L -> R -> D
        postOrderTraversal(cur->left, res);
        postOrderTraversal(cur->right, res);
        res.push_back(cur->val);
    }
};
