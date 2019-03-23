//
// Created by colin on 2018-12-12.
//

#ifndef PROJECT_BINARY_TREE_H
#define PROJECT_BINARY_TREE_H

#include <string>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* stringToTreeNode(std::string input);
std::string treeNodeToString(TreeNode* root);
std::string integerVectorToString(std::vector<int> list, int length = -1);




#endif //PROJECT_BINARY_TREE_H
