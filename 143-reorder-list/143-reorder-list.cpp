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
    //Storing (start, mid] elements in a queue..
    //Storing [mid, end] elements in a stack..
    //then interate in the linked list, and then reset its value with queue front value then stack top value
    void reorderList(ListNode* head) {
        int n=0, i=0;
        ListNode* temp = head, *start = head;
        
        //Calcualting middle element..
        while(temp)
        {
            temp=temp->next;    n++;
        }
        ListNode* mid = head;
        while(i++<n/2)  mid=mid->next;
        
        //Storing them in queue and stack respectively..
        queue<int> q;
        stack<int> st;
        i=0;
        while(i++<n/2)
        {
            q.push(start->val);
            start = start->next;
        }
        while(mid)
        {
            st.push(mid->val);
            mid=mid->next;
        }
        
        //now resetting the values in list..
        temp=head;
        while(!q.empty() or !st.empty())
        {
            if(!q.empty())
            {
                temp->val = q.front();
                q.pop();
                temp=temp->next;
            }
            if(!st.empty())
            {
                temp->val = st.top();
                st.pop();
                temp=temp->next;
            }
        }
        
    }
};