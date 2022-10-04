class Solution {
public:
    int findTheWinner(int n, int k) {
        if(n==1)    return 1;
        vector<int> v;
        for(int i=1; i<=n; i++) v.push_back(i);
        
        int start_ind = 0;
        while(v.size()>1)
        {
            n = v.size();
            int stop_ind = (start_ind + k - 1)%n;
            v.erase(v.begin() + stop_ind);
            start_ind = (stop_ind)%n;
        }
        
        return v[0];
    }
};