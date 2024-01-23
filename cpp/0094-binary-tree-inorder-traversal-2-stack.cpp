#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> list;
        TreeNode *node = root;
        stack<TreeNode *> s;
        while (node != nullptr || !s.empty())
        {
            while (node != nullptr)
            {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            list.push_back(node->val);
            node = node->right;
        }
        return list;
    }
};

int main()
{
    TreeNode *tree = new TreeNode(val, new TreeNode(4, TreeNode(3, nullptr, nullptr), nullptr), nullptr);
    vector<int> res = Solution().inorderTraversal();
}