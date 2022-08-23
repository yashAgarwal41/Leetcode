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
    ListNode* reverse(ListNode* head)
    {
        if(head->next==NULL or head==NULL)  return head;    
        ListNode *newhead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        int n=0;
        ListNode* temp = head, *mid = head;
        while(temp!=NULL)
        {
            n++;
            temp = temp->next;
        }
        
        int m = n/2;
        if(n%2 == 0) m--; 
        while(m--)
        {
            mid = mid->next;   
        }
        ListNode* last = reverse(mid), *start = head;
        
        while(start and last)
        {
            if(start->val!=last->val)   return false;
            start = start->next;
            last = last->next;
        }
        return true;
    }
};