class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        int n = v.size(), ans=0, cnt=1;
        multiset<int> set;
        unordered_map<int, int> map;
        for(auto i:v)   set.insert(i), map[i]++;
        
        int maxi = -1;
        for(int i=0; i<n; i++)
        {
            if(v[i] >= maxi)
            {
                auto it = set.find(maxi);
                if(it!=set.end()) set.erase(it);
                maxi = v[i];
            }
            else 
            {
                auto it = set.find(v[i]);
                set.erase(it);
            }
            auto it = set.begin();
            if(*it == maxi)
            {
                ans++;
                auto it1 = set.find(v[i]);
                auto it2 = set.find(maxi);
                // if(it1!=set.end())  set.erase(it1);
                if(it2!=set.end())  set.erase(it2);
                // if(i<n-1)   maxi = v[i+1];
                maxi = -1;
                continue;
            }
            
        }
        
        return ans;
    }
};