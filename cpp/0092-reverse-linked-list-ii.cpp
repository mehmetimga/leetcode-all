
#include <iostream>

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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *groupHead = head;
        ListNode *prev = nullptr;
        int i = 0;
        while (left > 1)
        {
            left--;
            right--;
            prev = groupHead;
            groupHead = groupHead->next;
        }

        ListNode *groupTail = groupHead;
        while (right > 1)
        {
            right--;
            groupTail = groupTail->next;
        }
        ListNode *curr = groupHead->next;
        groupHead->next = groupTail->next;
        ListNode *groupPrev = prev;
        ListNode *groupNext = groupTail->next;

        prev = groupHead;
        ///
        while (curr != groupNext)
        {

            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        if (groupPrev == nullptr)
            head = groupTail;
        else
            groupPrev->next = groupTail;
        groupHead->next = groupNext;

        return head;
    }
};

// 1,2,3,4,5
int main()
{
    //    ListNode *block2 = new ListNode(9, new ListNode(10, new ListNode(11)));
    //    ListNode *block1 = new ListNode(5, new ListNode(6, new ListNode(7, new ListNode(8,block2))));
    // ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4,block1))));
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, nullptr))));

    head = Solution().reverseBetween(head, 2, 3);
    ListNode *node = head;
    while (node != nullptr)
    {
        cout << node->val << ",";
        node = node->next;
    }
    cout << endl;
    return 0;
}