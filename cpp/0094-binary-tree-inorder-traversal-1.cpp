#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void inorderT(TreeNode *root, vector<int> &list)
    {
        if (root == nullptr)
            return;
        inorderT(root->left, list);
        list.push_back(root->val);
        inorderT(root->right, list);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> list;
        inorderT(root, list);
        return list;
    }
};

int main()
{
    TreeNode *tree = new TreeNode(val, new TreeNode(4, TreeNode(3, nullptr, nullptr), nullptr), nullptr);
    vector<int> res = Solution().inorderTraversal();
}