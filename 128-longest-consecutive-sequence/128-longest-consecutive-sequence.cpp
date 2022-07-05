class Solution {
public:
    //Unorederd_set..TC-O(n)
    //Reach to the smalest element and then check from that..
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(auto &it:nums)  set.insert(it);
        
        int maxi=0;
        for(auto &it:set)
        {
            int smallest = it;
            if(set.count(smallest-1))   continue;
            else 
            {
                int count=1;
                smallest++;
                while(set.count(smallest))
                {
                    count++;
                    smallest++;
                }
                maxi = max(maxi, count);
            }
            
            
        }
        return maxi;
    }
};