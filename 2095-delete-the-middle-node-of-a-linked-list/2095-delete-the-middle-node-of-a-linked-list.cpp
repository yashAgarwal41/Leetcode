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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL)  return NULL;
        ListNode *slow = head, *fast = head, *prevOfSlow;
        while(fast and fast->next)
        {
            prevOfSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prevOfSlow->next = slow->next;
        return head;
    }
};