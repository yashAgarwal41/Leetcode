class Solution {
public:
    //3 pointers, TC-O(n*n)
    int threeSumClosest(vector<int>& v, int target) {
        int n = v.size(), ans = 1e6;    
        sort(v.begin(), v.end());
        
        for(int i=0; i<n; i++)
        {
            int j = i+1, k = n-1;
            while(j<k)
            {
                int sum = v[i] + v[j] + v[k];
                if(abs(sum-target) < abs(ans-target))  ans = sum;
                if(sum > target)    k--;
                else j++;
            }
        }
        return ans;
    }
};
