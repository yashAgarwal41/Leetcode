class Solution {
public:
    //4 POinters, TC-O(n^3), SC-O(1)..
    vector<vector<int>> fourSum(vector<int>& v, int target) {
        int n = v.size();
        sort(v.begin(), v.end());
        vector<vector<int>> res;
        for(int i=0; i<n; i++)
        {
            if(i>0 and v[i]==v[i-1])    continue;
            for(int j=i+1; j<n; j++)
            {
                if(j>i+1 and v[j]==v[j-1])  continue;
                long long target2 = target + 0LL - v[i] - v[j];
                int low=j+1, high=n-1, x=INT_MAX, y=INT_MAX;
                while(low<high)
                {
                    if(v[low]==x)   low++;
                    else if(v[high]==y)  high--;
                    else if(v[low] + v[high] == target2)
                    {
                        x=v[low], y=v[high];
                        res.push_back({v[i], v[j], v[low], v[high]});
                    }
                    else if(v[low]+v[high]>target2)
                        high--;
                    else low++;
                }
            }
        }
        return res;
    }
};