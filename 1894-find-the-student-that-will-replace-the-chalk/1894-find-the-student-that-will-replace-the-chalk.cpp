#define ll long long
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        ll sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        k %= sum;
        for(int i=0; i<n; i++)
        {
            k -= chalk[i];
            if(k<0)  return i;
        }
        return -1;
    }
};