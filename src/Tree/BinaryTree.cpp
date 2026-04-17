#include "BinaryTree.h"
#include "common/TreeNode.h"
#include <iostream>

void in(TreeNode* root);
void pre(TreeNode* root);
void post(TreeNode* root);

void BinaryTree::inOrder() {
    in(root);
    std::cout << std::endl;
}

void BinaryTree::preOrder() {
    pre(root);
    std::cout << std::endl;
}

void in(TreeNode* root) {
    in(root->left);
    std::cout << root->val << " ";
    in(root->right);
}

void pre(TreeNode* root) {
    std::cout << root->val << " ";
    pre(root->left);
    pre(root->right);
}