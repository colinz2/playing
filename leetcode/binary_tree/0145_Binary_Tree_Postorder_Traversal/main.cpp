//
// Created by colin on 2018-12-12.
//

//二叉树的后序遍历



#include "../binary_tree.h"
#include "leetcode.h"

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root != NULL) {
            vector<int> L = postorderTraversal(root->left);
            vector<int> R = postorderTraversal(root->right);
            res.insert(res.end(), L.begin(), L.end());
            res.insert(res.end(), R.begin(), R.end());
            res.push_back(root->val);
        }
        return res;
    }

    vector<int> postorderTraversal2(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;

        stack<TreeNode*> stack, output;

        TreeNode* p = root;
        while (p != NULL || !stack.empty()) {
            if (p != NULL) {
                stack.push(p);
                output.push(p);
                p = p->right;
            } else {
                p = stack.top();
                stack.pop();
                p = p->left;
            }
        }

        while (!output.empty()) {
            res.push_back((output.top())->val);
            output.pop();
        }
        return res;
    }

};

int main() {

    TreeNode* root = stringToTreeNode("1,2,3,4,5");
    TreeNode* root2 = stringToTreeNode("1,2,3,4,5");

    vector<int> ret = Solution().postorderTraversal(root);
    vector<int> ret2 = Solution().postorderTraversal2(root2);

    cout << integerVectorToString(ret) << endl;
    cout << integerVectorToString(ret2) << endl;
    return 0;
}