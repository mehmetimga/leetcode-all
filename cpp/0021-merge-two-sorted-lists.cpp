#include <iostream>

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode(0);
        ListNode *curr = head;
        ListNode *p1 = list1;
        ListNode *p2 = list2;

        if (!list1)
        {
            return list2;
        }
        if (!list2)
        {
            return list1;
        }

        while (p1 && p2)
        {
            if (p2 == nullptr || (p1 != nullptr && p1->val < p2->val))
            {
                curr->next = new ListNode(p1->val);
                p1 = p1->next;
            }
            else
            {
                curr->next = new ListNode(p2->val);
                p2 = p2->next;
            }
            curr = curr->next;
        }
        if (p1 == nullptr)
            curr->next = p2;
        else
            curr->next = p1;

        return head->next;
    }
};