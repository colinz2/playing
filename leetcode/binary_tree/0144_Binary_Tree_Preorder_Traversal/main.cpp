//
// Created by colin on 2018-12-12.
//

#include "../binary_tree.h"
#include "leetcode.h"

class Solution {
public:
    //递归
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root != NULL) {
            res.push_back(root->val);
            vector<int> L = preorderTraversal(root->left);
            vector<int> R = preorderTraversal(root->right);
            res.insert(res.end(), L.begin(), L.end());
            res.insert(res.end(), R.begin(), R.end());
        }
        return res;
    }

    //并不好，👎
    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (root == NULL)
            return res;

        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
        return res;
    }

    //👌，😄
    vector<int> preorderTraversal3(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;

        stack<TreeNode*> stack;
        TreeNode* cur = root;

        while (cur != NULL || !stack.empty()) {
            if (cur != NULL){
                res.push_back(cur->val);
                stack.push(cur);
                cur = cur->left;
            } else {
                cur = stack.top();
                stack.pop();
                cur = cur->right;
            }
        }
        return res;
    }
};

int main() {

    TreeNode* root = stringToTreeNode("1,2,3,4,5");
    TreeNode* root2 = stringToTreeNode("1,2,3,4,5");

    vector<int> ret = Solution().preorderTraversal(root);
    vector<int> ret2 = Solution().preorderTraversal2(root2);

    cout << integerVectorToString(ret) << endl;
    cout << integerVectorToString(ret2) << endl;
    return 0;
}