class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n = nums.size(), ans=0;
        long double sum = accumulate(nums.begin(), nums.end(), 0LL);
        long double currSum = sum;
        sum /= 2.0;
        cout<<sum<<" "<<currSum<<endl;
        priority_queue<double> pq;
        for(auto it:nums)   pq.push(it);
        
        while(currSum>sum)
        {
            double x = pq.top();
            pq.pop();
            currSum -= x/2.0;
            pq.push(x/2.0);
            ans++;
        }
        return ans;
    }
};