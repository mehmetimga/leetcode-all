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
    ListNode *switchR(ListNode *node)
    {
        if (node == nullptr || node->next == nullptr)
            return node;
        ListNode *temp = node->next->next;
        node->next->next = node;
        ListNode *temp2 = node->next;
        node->next = temp;
        node = temp2;

        node->next->next = switchR(node->next->next);
        return node;
    }

    ListNode *swapPairs(ListNode *head)
    {
        return switchR(head);
    }
};

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    head = Solution().swapPairs(head);
    ListNode *node = head;
    while (node)
    {
        cout << node->val << ",";
        node = node->next;
    }
    return 0;
}
