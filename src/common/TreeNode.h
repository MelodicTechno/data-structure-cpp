#pragma once

// Binary Tree Node. Leetcode call

struct TreeNode {
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode() {}
    TreeNode(int val) : val(val) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};