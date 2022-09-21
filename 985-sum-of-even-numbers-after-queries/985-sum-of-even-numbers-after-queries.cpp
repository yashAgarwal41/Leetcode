class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& v, vector<vector<int>>& queries) {
        int sum=0;
        for(auto &i : v)    
        {
            if(i%2==0)  sum += i;
        }
        vector<int> res;
        
        for(auto &q : queries)
        {
            int newVal = q[0] + v[q[1]];
            if(v[q[1]]%2)
            {
                if(newVal%2 == 0)
                {
                    sum += newVal;
                }
            }
            else 
            {
                if(newVal % 2)
                {
                    sum -= v[q[1]];
                }
                else 
                {
                    sum += q[0];
                }
            }
            v[q[1]] = newVal;
            res.push_back(sum);
        }
        return  res;
    }
};