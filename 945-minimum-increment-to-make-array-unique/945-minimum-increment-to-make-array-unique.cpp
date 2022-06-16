class Solution {
public:
    //Greedy..
    int minIncrementForUnique(vector<int>& v) {
        int n=v.size();
        sort(v.begin(), v.end());
        int prev = v[0], ans=0;
        for(int i=1; i<n; i++)
        {
            int curr = v[i];
            if(prev<curr)
            {
                prev = curr;
            }
            else 
            {
                ans += prev-curr+1;
                prev = curr + (prev-curr+1);
            }
        }
        return ans;
    }
};

    // 1-2
    // 2-2
    // 3-1
    // 7-1
        
        