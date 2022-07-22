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
        ListNode* smallHead = new ListNode(0);
        ListNode* largeHead = new ListNode(0);
        ListNode* newHead = smallHead, *temp = largeHead;
        while(head)
        {
            int data = head->val;
            if(data<x)
            {
                smallHead->next = head;
                smallHead = head;
            }
            else 
            {
                largeHead->next = head;
                largeHead = head;
            }
            head = head->next;
        }
        largeHead->next = NULL;
        smallHead->next = temp->next;
        return newHead->next;
    }
};