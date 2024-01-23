#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// 0	none (on some telephones, "OPERATOR" or "OPER")
// 1	none (on some older telephones, QZ)
// 2	ABC
// 3	DEF
// 4	GHI
// 5	JKL
// 6	MNO (on some older telephones, MN)
// 7	PQRS (on older telephones, PRS)
// 8	TUV
// 9	WXYZ (on older telephones, WXY)

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *forward = dummy;
        ListNode *front = dummy;

        for (int i = 0; i < n; i++)
            forward = forward->next;
        while (forward->next)
        {
            forward = forward->next;
            front = front->next;
        }
        ListNode *temp = front->next;
        front->next = front->next->next;
        delete temp;
        return dummy->next;
    }
};
int main()
{
    // ListNode* head= new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5,new ListNode(6,new ListNode(7,new ListNode(8,new ListNode(9,new ListNode(10,new ListNode(11)))))))))));
    ListNode *head = new ListNode(1);
    ListNode *result = Solution().removeNthFromEnd(head, 1);

    return 0;
}