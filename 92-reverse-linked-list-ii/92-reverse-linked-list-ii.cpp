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
    //recursive..TC-O(n)..
    //leftNode - node from which reverse will start, i.e, node[left](in e.g-1, node->'2')..
    //prev - just prev node node[left](in e.g-1, node->'1'), i.e prev of leftNode.
    //last - just next node of node[right](in e.g-1, node->'5')..
    //rightNode - node[right]..(in e.g-1, node->'4')..
    ListNode* reverse(ListNode* head, int n)
    {
        if(n==0)    return head;
        ListNode *newHead = reverse(head->next, n-1);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next == NULL)  return head;
        int n = right-left;
        ListNode *leftNode = head, *prev = NULL, *last = head;
        for(int i=1; i<left; i++)
        {
            prev = leftNode;
            leftNode = leftNode->next; 
        }
        for(int i=1; i<=right; i++)
        {
            last = last->next;
        }
        ListNode* rightNode = reverse(leftNode, n); //rightNode after reverse
        leftNode->next = last;  //point leftNode to lastNode..
        if(prev==NULL)  //if reversing start from 1st node
        {
            return rightNode;
        }
        prev->next = rightNode; //point prevNode to righNode..
        return head;
    }
};