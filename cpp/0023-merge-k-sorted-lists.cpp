/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<ListNode *> listitems;
        ListNode *head = new ListNode(-1);
        ListNode *curr = head;
        for (auto i : lists)
        {
            listitems.push_back(i);
        }
        int minitem = 0;
        int minindex = INT_MAX;
        while (minitem != INT_MAX)
        {

            minitem = INT_MAX;
            int j = 0;
            for (auto i : listitems)
            {
                if (i != nullptr && minitem > i->val)
                {
                    minindex = j;
                    minitem = i->val;
                }
                j++;
            }
            if (minitem < INT_MAX)
            {
                curr->next = new ListNode(minitem);
                curr = curr->next;
                listitems[minindex] = listitems[minindex]->next;
            }
        }
        return head->next;
    }
};