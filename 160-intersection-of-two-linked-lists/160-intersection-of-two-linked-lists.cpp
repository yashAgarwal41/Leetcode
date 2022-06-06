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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=0, m=0;
        ListNode *temp1=headA, *temp2 = headB;
        while(temp1)
        {
            temp1=temp1->next;
            n++;
        }
        while(temp2)
        {
            temp2=temp2->next;
            m++;
        }
        temp1=headA, temp2 = headB;
        int diff1 = n-min(n, m);
        int diff2 = m-min(n, m);
        while(diff1--)  temp1=temp1->next; 
        while(diff2--)    temp2=temp2->next;
        while(temp1 and temp2)
        {
            if(temp1 == temp2)  return temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};