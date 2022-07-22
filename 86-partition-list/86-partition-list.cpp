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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL or head->next==NULL)  return head;
        vector<int> small, large;
        while(head!=NULL)
        {
            int data = head->val;
            if(data<x)  small.push_back(data);
            else large.push_back(data);
            head=head->next;
        }
        
        ListNode* newHead = NULL, *temp=NULL;
        if(small.size())    
        {
            ListNode *n = new ListNode(small[0]);
            newHead = n;
            temp = newHead;
        }
        else 
        {
            ListNode *n = new ListNode(large[0]);
            newHead = n;
            temp = newHead;
        }
        for(int i=1; i<small.size(); i++)
        {
            ListNode *n = new ListNode(small[i]);
            temp->next = n;
            temp = temp->next;
        }
        for(int i=0; i<large.size(); i++)
        {
            if(i==0 and newHead->val==large[0]) continue;
            ListNode *n = new ListNode(large[i]);
            temp->next = n;
            temp = temp->next;
        }
        return newHead;
    }
};