class Solution {
public:
    //Sliding window..TC-O(nlogn)..
    int maxFrequency(vector<int>& v, int k) {
        int n = v.size();
        int i=0, j=0;
        long long sum=0, maxi=1;
        sort(v.begin(), v.end());
        //1, 2, 3, 4..-> sum = 10
        //4, 4, 4, 4 -> sumShouldBe = 16
        //so required moves = sumShouldBe - sum = 16-10 = 6 moves..
        while(i<n and j<n)
        {
            sum += v[j];
            long long sumShouldBe = v[j]*(j-i+1LL);
            while(sumShouldBe - sum > k)
            {
                sum -= v[i];
                i++;
                sumShouldBe = v[j]*(j-i+1LL);
            }
            maxi = max(maxi, j-i+1LL);
            j++;
        }
        return maxi;
    }
};