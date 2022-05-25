class Solution {
public:
    //Binary search..TC-O(nlogn)..
    
    int lengthOfLIS(vector<int>& v) {
        int n=v.size();
        vector<int> lis;    //this will contain the maximum size of the subsequence..
        lis.push_back(v[0]);
        for(int i=1; i<n; i++)
        {   
            int ind = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            if(ind>=lis.size()) lis.push_back(v[i]);    //if smaller element found..
            else lis[ind] = v[i];   //if bigger element found..
        }

        return lis.size();
        
    }
};