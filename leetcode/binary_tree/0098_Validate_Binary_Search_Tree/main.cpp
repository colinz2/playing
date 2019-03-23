//
// Created by colin on 2018-12-13.
//

//给定一个二叉树，判断其是否是一个有效的二叉搜索树。
//
//假设一个二叉搜索树具有如下特征：
//
//节点的左子树只包含小于当前节点的数。
//节点的右子树只包含大于当前节点的数。
//所有左子树和右子树自身必须也是二叉搜索树。

#include "../binary_tree.h"
#include "leetcode.h"

class Solution {
public:
    //中序遍历，从小到大排列, 左<根<右
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorderVisit(root, v);
        for (int i = 1; i < v.size(); i++) {
            if (v[i - 1] >= v[i]) {
                return false;
            }
        }
        return true;
    }

    void inorderVisit(TreeNode* root, vector<int>& v) {
        if (root) {
            inorderVisit(root->left, v);
            v.push_back(root->val);
            inorderVisit(root->right, v);
        }
    }

    //使用栈
    bool isValidBST2(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *p = root, *pre = NULL;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            TreeNode *t = s.top();
            s.pop();
            if (pre && t->val <= pre->val) return false;
            pre = t;
            p = t->right;
        }
        return true;
    }
};

int main() {
    TreeNode* root = stringToTreeNode("1,2,3,4,5,6,7,9");
    cout <<  Solution().isValidBST(root) << endl;
}

