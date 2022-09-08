class Solution {
public:
    int longestSubarray(vector<int>& v, int limit) {
        int n = v.size(), maxi=1;
        multiset<int> set;
        int i=0, j=0;
        
        while(i<n and j<n)
        {
            set.insert(v[j]);
            int low = v[j]-limit, high = v[j]+limit;
            while(true)
            {
                if(set.size()==0)   break;
                auto beg = set.begin();
                auto en = set.end();
                en--;
                if(*beg >= low and *en <= high)  break;
                set.erase(set.find(v[i]));
                i++;
            }
            // cout<<"i: "<<i<<", j: "<<j<<" -> ";
            // for(auto it:set)    cout<<it<<" ";
            // cout<<endl;
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};