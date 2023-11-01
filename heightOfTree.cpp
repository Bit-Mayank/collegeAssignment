#include <iostream>
#include <algorithm>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;

    int leftHeight = 0, rightHeight = 0;
    if (root->left)
    {
        leftHeight += height(root->left);
    }

    if (root->right)
    {
        rightHeight += height(root->right);
    }

    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(3);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(5);
    root->right->left->right = new TreeNode(5);
    root->right->left->right->left = new TreeNode(5);

    int cnt = height(root);

    cout << cnt << endl;
}