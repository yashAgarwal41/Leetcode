class Solution {
public:
    //Using Set..TC-O(nlogn)
    //minimum no should be there in a chunk..
    int maxChunksToSorted(vector<int>& v) {
        int n = v.size();
        set<int> set;
        for(auto i:v)   set.insert(i);
        
        int ans = 0, maxi=-1;      
        for(int i=0; i<n; i++)
        {
            if(v[i] >= maxi)
            {
                if(set.count(maxi))  set.erase(maxi);
                maxi = v[i];
            }
            else set.erase(v[i]);
            
            auto it = set.begin();
            if(*it == maxi)
            {
                if(set.count(maxi))  set.erase(maxi);
                ans++;
                maxi = -1;
            }
        }
        return ans;
    }
};