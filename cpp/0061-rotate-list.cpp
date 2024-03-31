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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || k == 0)
            return head;

        int len = 1;
        ListNode *node = head;
        ListNode *tail = head;
        while (tail->next)
        {
            tail = tail->next;
            len++;
        }
        int m = k % len;
        node = head;
        int i = 1;
        while (node)
        {

            if (i == len - m)
                break;
            i++;

            node = node->next;
        }
        tail->next = head;
        head = node->next;
        node->next = nullptr;
        return head;
    }
};