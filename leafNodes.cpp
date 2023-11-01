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

int leafNode(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int cnt = 0;
    if (!root->left && !root->right)
    {
        cnt++;
    }

    cnt += leafNode(root->left);
    cnt += leafNode(root->right);

    return cnt;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(5);

    int cnt = leafNode(root);

    cout << cnt << endl;
}