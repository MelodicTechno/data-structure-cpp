#include <iostream>

using namespace std;

// The code of Binary Search Tree

struct BSTNode
{
    BSTNode* left;
    BSTNode* right;
    int val;

    BSTNode(int val): val(val), left(nullptr), right(nullptr) {}
};


int bstInsert(BSTNode* t, int k)
{
    if (t == nullptr)
    {
        t = new BSTNode(k);
        return 1;
    }
}

BSTNode* bstSearch(BSTNode* root, int key)
{
    BSTNode* t = root;
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

void createBST(BSTNode* root, int* a, int n)
{
    int i = 0;
    while (i < n)
    {
        bstInsert(root, a[i]);
        i++;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    
}