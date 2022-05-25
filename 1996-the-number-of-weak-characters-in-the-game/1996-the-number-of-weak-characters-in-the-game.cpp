class Solution {
public:
    //Similar to LIS approach..
    //Binary Search TC-O(nlogn)..
    //sort according to first value. If first value matches, then sort according to second value in decresing order..
//now move from right to left and take maximum second element at every index. 
//now if v[i][1]<maxi , ans++;
//else update the maxi = v[i][1];
    static bool compare(vector<int> &v1, vector<int> &v2)
    {
        return (v1[0]==v2[0]) ? (v1[1]>v2[1]) : (v1[0]<v2[0]);
    }
    int numberOfWeakCharacters(vector<vector<int>>& v) {
        int n=v.size(), ans=0;
        sort(v.begin(), v.end(), compare);

        int maxi = v[n-1][1];
        for(int i=n-2; i>=0; i--)
        {
            if(maxi > v[i][1])  ans++;
            else maxi=max(maxi, v[i][1]);
        }
        
        return ans;
    }
};