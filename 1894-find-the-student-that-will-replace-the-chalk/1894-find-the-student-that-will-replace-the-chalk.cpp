#define ll long long
class Solution {
public:
    //Check the remainder of k with suffix sum...
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        ll sum = accumulate(chalk.begin(), chalk.end(), 0LL);   //suffixSum..
        for(int i=0; i<n; i++)
        {
            if(chalk[i] > k)  return i;
            int rem = k%sum;
            if(chalk[i] > rem) return i;
            k -= chalk[i];
        }
        return -1;
    }
};