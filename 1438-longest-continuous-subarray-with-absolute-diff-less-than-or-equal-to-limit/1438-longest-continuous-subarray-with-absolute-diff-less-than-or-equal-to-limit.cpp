class Solution {
public:
    //sliding window + multiset, TC-O(nlogn)
    int longestSubarray(vector<int>& v, int limit) {
        int n = v.size(), maxi=1;
        map<int, int> map;
        int i=0, j=0;
        
        while(i<n and j<n)
        {
            map[v[j]]++;
            int low = v[j]-limit, high = v[j]+limit;
            while(true)
            {
                if(map.size()==0)   break;
                auto beg = map.begin();
                auto en = map.end();
                en--;
                if(beg->first >= low and en->first <= high)  break;
                map[v[i]]--;
                if(map[v[i]]==0)    map.erase(v[i]);
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};