class Solution {
public:
    //Slow-fast pointer..TC-O(n), without modifying array..
    int findDuplicate(vector<int>& nums) {
        int slow=0, fast=0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
            
        int head=0, meet = slow;
        while(head!=meet)
        {
            head = nums[head];
            meet = nums[meet];
        }
        return head;
    }
};