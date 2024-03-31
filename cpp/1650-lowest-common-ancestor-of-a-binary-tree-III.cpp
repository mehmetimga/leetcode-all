/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution
{
public:
    int getDepth(Node *node)
    {
        int i = 0;
        while (node != nullptr)
        {
            i++;
            node = node->parent;
        }
        return i;
    }

    Node *lowestCommonAncestor(Node *p, Node *q)
    {
        int k = getDepth(p);
        int l = getDepth(q);
        Node *a = p;
        Node *b = q;

        while (k > l)
        {
            k--;
            a = a->parent;
        }
        while (l > k)
        {
            l--;
            b = b->parent;
        }
        while (a != b && b != nullptr && a != nullptr)
        {
            a = a->parent;
            b = b->parent;
        }
        return a;
    }
};