class Solution {
public:
    //Iterative, TC-O(n*n)
    string getPermutation(int n, int k) {
        k--;
        int nfact = 1;
        vector<int> nums;
        for(int i=1; i<=n; i++)
        {
            nums.push_back(i);
            nfact *= i;
        }
        
        int part = nfact/n;
        string ans="";
        for(int i=0; i<n; i++)
        {
            ans += to_string(nums[k/part]);
            nums.erase(nums.begin() + k/part);
            if(nums.size()==0)  break;
            k = k%part;
            part = part/nums.size();
        }
        return ans;
    }
};