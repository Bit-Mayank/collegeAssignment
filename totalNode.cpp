#include <iostream>
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

int totalNode(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int cnt = 0;
    cnt++;

    cnt += totalNode(root->left);
    cnt += totalNode(root->right);

    return cnt;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(5);
    root->right->left = new TreeNode(5);

    int cnt = totalNode(root);

    cout << cnt << endl;
}