//
// Created by colin on 2018-12-14.
//

//翻转一棵二叉树。
//
//示例：
//
//输入：
//
//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9
//输出：
//
//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1

#include "../binary_tree.h"
#include "leetcode.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            swap(root->right, root->left);
            invertTree(root->right);
            invertTree(root->left);
            return root;
        } else {
            return NULL;
        }
    }

    TreeNode* invertTree2(TreeNode* root) {
        if (root == NULL) return root;
        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            swap(node->right, node->left);
            if (node->right) q.push(node->right);
            if (node->left) q.push(node->left);
        }

        return root;
    }
};

int main() {

    TreeNode* root = stringToTreeNode("1,2,3,4,5,6");
    TreeNode* root2 = stringToTreeNode("1,2,3,4,5");

    TreeNode* r = Solution().invertTree(root);
    TreeNode* r2 = Solution().invertTree2(root);
    cout << treeNodeToString(r) << endl;
    cout << treeNodeToString(r2) << endl;

    return 0;
}