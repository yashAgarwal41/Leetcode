class Solution {
public:
    //2pointers, TC-O(n-k)+O(k)..
    vector<int> findClosestElements(vector<int>& v, int k, int x) {
        int n = v.size();
        int low=0, high = n-1;
        while(high-low+1>k)
        {
            int a = abs(x-v[low]);
            int b = abs(x-v[high]);
            if(a>b) low++;
            else high--;
        }
        vector<int> res;
        for(int i=low; i<=high; i++)
        {
            res.push_back(v[i]);
        }
        return res;
    }
};