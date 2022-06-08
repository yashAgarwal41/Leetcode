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
    void reorderList(ListNode* head) {
        if(!head->next or !head->next->next)    return;
        
        ListNode* temp=head;
        stack<ListNode*> st;
        int n=0;
        while(temp)
        {
            st.push(temp);
            temp=temp->next;
            n++;
        }
        
        ListNode* ptr = head;
        for(int i=0; i<n/2; i++)
        {
            ListNode * newNode = st.top();
            st.pop();
            newNode->next = ptr->next;
            ptr->next = newNode;
            ptr = newNode->next;
        }
        ptr->next = NULL;
    }
};