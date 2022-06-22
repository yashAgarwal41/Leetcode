/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        bool ch = 0;
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                ch = 1;
                break;
            }
        }
        if(!ch) return NULL;
        while(slow != head)
        {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};