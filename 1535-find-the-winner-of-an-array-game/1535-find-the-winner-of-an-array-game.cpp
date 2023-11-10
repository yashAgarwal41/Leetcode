class Solution {
public:
    int getWinner(vector<int>& v, int k) {
        int n = v.size();
        int maxi = *max_element(v.begin(), v.end());
        unordered_map<int, int> map1;
        for(int i=0; i<n-1; i++)
        {
            if(v[i] > v[i+1])   swap(v[i], v[i+1]);
            map1[v[i+1]]++;
            if(map1[v[i+1]] == k)   return v[i+1];
        }
        return maxi;
    }
};