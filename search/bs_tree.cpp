#include <iostream>

using namespace std;

// The code of Binary Search Tree

struct BSTNode
{
    BSTNode* left;
    BSTNode* right;
    int val;

    BSTNode(int val): val(val), left(nullptr), right(nullptr) {}
    BSTNode(): val(-INT_MIN), left(nullptr), right(nullptr) {}
};


BSTNode* bstInsert(BSTNode* t, int k)
{
    if (t == nullptr)
    {
        t = new BSTNode(k);
        return t;
    }
    else if (k < t->val)
    {
        t->left = bstInsert(t->left, k);
    }
    else if (k > t->val)
    {
        t->right = bstInsert(t->right, k);
    }
    return t;
}

BSTNode* bstSearch(BSTNode* t, int key)
{
    while (t != nullptr && key != t->val)
    {
        if (key < t->val)
        {
            t = t->left;
        }
        else
        {
            t = t->right;
        }
    }
    return t;
}

void createBST(BSTNode*& root, int* a, int n)
{
    root = nullptr;
    int i = 0;
    while (i < n)
    {
        root = bstInsert(root, a[i]);
        i++;
    }
}

void traverse(BSTNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    
    traverse(root->left);
    cout << root->val << endl;
    traverse(root->right);
}

int main()
{
    int a[] = {45, 24, 53, 12, 24};
    BSTNode* root = nullptr;
    createBST(root, a, 5);
    traverse(root);
    cout << bstSearch(root, 53) << ": " << bstSearch(root, 53)->val << endl;
    cout << bstSearch(root, 24) << ": " << bstSearch(root, 24)->val << endl;
}