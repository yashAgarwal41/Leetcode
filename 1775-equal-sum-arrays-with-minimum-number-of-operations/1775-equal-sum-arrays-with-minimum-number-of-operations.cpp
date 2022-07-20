class Solution {
public:
    //Greedy..TC-O(nlogn)..
    int minOperations(vector<int>& v1, vector<int>& v2) {
        int n = v1.size(), m = v2.size();
        if(n*6 < m or n > 6*m)  return -1;
        int sum1 = accumulate(v1.begin(), v1.end(), 0);
        int sum2 = accumulate(v2.begin(), v2.end(), 0);
        int diff = sum1-sum2;
        //taking sum1 as smaller and sum2 as larger.. so we increement in v1 and decreement in v2
        if(diff==0) return 0;
        if(diff>0)  swap(v1, v2);   
        diff = abs(diff);
        
        int ans = 0;
        vector<int> freq;
        for(auto it:v1) freq.push_back(6-it);   //convert v1[i] to '6' and store the increement..
        for(auto it:v2) freq.push_back(it-1);   //convert v2[i] to '1' and store the decreement..
        sort(freq.rbegin(), freq.rend());
        
        for(auto &it : freq)
        {
            diff -= it;
            ans++;
            if(diff<=0) break;
        }
        return ans;
    }
};