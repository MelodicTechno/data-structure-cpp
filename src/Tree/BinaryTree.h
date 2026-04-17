#pragma once

#include "common/TreeNode.h"
#include <vector>
#include <string>

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree(TreeNode* root) : root(root) {}

    BinaryTree(std::vector<std::string> nodes) {
        for (std::string node : nodes) {
            if (node != "null") {
                
            }
        }
    }

    void preOrder();
    void inOrder();
    void postOrder();
};