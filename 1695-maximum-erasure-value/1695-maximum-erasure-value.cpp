class Solution {
public:
    //Using Sets..
    int maximumUniqueSubarray(vector<int>& v) {
        int n=v.size(), i=0, j=0;
        int maxi=0, sum=0;
        unordered_set<int> set;
        while(j<n)
        {
            while(set.find(v[j])!=set.end())
            {
                sum-=v[i];
                set.erase(v[i]);
                i++;
            }
            set.insert(v[j]);
            sum+=v[j];
            j++;
            maxi=max(maxi, sum);
        }
        return maxi;
    }
};