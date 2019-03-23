//
// Created by colin on 2018-12-12.
//

#include "../binary_tree.h"
#include "leetcode.h"

//层序遍历二叉树, 是典型的广度优先搜索BFS的应用
//REF:
//http://www.cnblogs.com/grandyang/p/4051321.html


class Solution {
public:
    //BFS
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;

        queue<TreeNode*> traversal_queue;
        traversal_queue.push(root);

        vector<int> level_res;
        while (!traversal_queue.empty()) {
            int level_node_cnt = traversal_queue.size();
            while (level_node_cnt--) {
                TreeNode* node = traversal_queue.front();
                traversal_queue.pop();
                level_res.push_back(node->val);

                if (node->left) traversal_queue.push(node->left);
                if (node->right) traversal_queue.push(node->right);
            }
            res.push_back(level_res);
            level_res.clear();
        }
        //For 107
        //vector<vector<int> > (res.rbegin(), res.rend())
        return res;
    }

    //递归
    vector<vector<int>> levelOrder2(TreeNode* root) {
        vector<vector<int>> res;
        levelOrder_recursion(root, 0, res);
        return res;
    }

    void levelOrder_recursion(TreeNode* node, int level, vector<vector<int>>& res) {
        if (node == nullptr) return;
        if (level == res.size()) {
            res.push_back(vector<int>());
        }
        res[level].push_back(node->val);
        if (node->left) levelOrder_recursion(node->left, level + 1, res);
        if (node->right) levelOrder_recursion(node->right, level + 1, res);
    }
};


int main() {

    TreeNode* root = stringToTreeNode("1,2,3,4,5,6,7,9");
    TreeNode* root2 = stringToTreeNode("1,2,3,4,5,6,7,9");

    vector<vector<int>> ret = Solution().levelOrder(root);
    vector<vector<int>> ret2 = Solution().levelOrder2(root2);

    for (auto &v : ret) {
        PrintVector(v);
    }
    cout << endl << endl;


    for (auto &v : ret2) {
        PrintVector(v);
    }
    cout << endl << endl;
    return 0;
}
