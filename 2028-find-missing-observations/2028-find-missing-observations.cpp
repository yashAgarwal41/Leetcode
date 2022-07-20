class Solution {
public:
    //Greedy..TC-O(n)..
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum2 = accumulate(rolls.begin(), rolls.end(), 0);
        int sum1 = (n+m)*mean - sum2;
        if(sum1 <= 0 or sum1 > n*6 or n>sum1) return {};
        // cout<<sum2<<" "<<sum1<<endl;
        
        vector<int> res(n);
        int temp = n;
        for(int i=0; i<n; i++)
        {
            res[i] = sum1/temp;
            sum1 -= sum1/temp;
            temp--;
        }
        return res;
    }
};