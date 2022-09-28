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
    //Single Pass, TC-O(no of nodes)..
    //take a pointer which is 'n' steps backward from the current pointer..
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *delay, *prev = NULL, *curr = head;
        int cnt=0; 
        
        while(curr->next!=NULL)
        {
            curr = curr->next;
            cnt++;
            if(cnt==n)  prev = head;
            else if(cnt>n)   prev = prev->next;
        }
        if(prev == NULL)    return head->next;  //means remove the 1st node
        prev->next = prev->next->next;
        return head;
    }
};