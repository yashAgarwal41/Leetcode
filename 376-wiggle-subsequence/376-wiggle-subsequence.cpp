class Solution {
public:
    //Greedy..TC-O(n), SC-O(1)..
    int wiggleMaxLength(vector<int>& v) {
        int n=v.size();
        int ans=0, prev=-1;     //prev- previous sign(1:+ve , 0:-ve)
        for(int i=0; i<n-1; i++)
        {
            if(v[i+1] == v[i]) continue;
            int curr = (v[i+1]> v[i]) ? 1 : 0;  //curr - sign of the current differnce..
            if(prev != curr)
            {
                ans++;
                prev = curr;
            }
        }
        return ans+1;
    }
};