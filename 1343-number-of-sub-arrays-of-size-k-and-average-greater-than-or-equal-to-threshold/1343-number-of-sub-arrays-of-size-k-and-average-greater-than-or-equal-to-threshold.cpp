class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size(), sum=0, ans=0;
        int i=0, j=0;
        while(j<n)
        {
            sum += arr[j];
            if(j-i+1==k)
            {
                int avg = sum/k;
                if(avg>=threshold)  ans++;
                sum -= arr[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};