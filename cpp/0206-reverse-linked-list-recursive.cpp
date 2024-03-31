#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseR(ListNode *node, ListNode *prev)
    {
        if (node == nullptr)
            return prev;

        ListNode *head = reverseR(node->next, node);
        node->next = prev;
        return head;
    }
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        return reverseR(head, nullptr);
    }
};

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, new ListNode(7, new ListNode(8, new ListNode(9, new ListNode(10, new ListNode(11, new ListNode(12, new ListNode(13, new ListNode(14))))))))))))));
    ListNode *node = head;
    while (node)
    {
        cout << node->val << ",";
        node = node->next;
    }

    head = Solution().reverseList(head);
    cout << endl;
    node = head;
    while (node)
    {
        cout << node->val << ",";
        node = node->next;
    }
    return 0;
}