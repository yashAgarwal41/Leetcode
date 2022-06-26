class Solution {
public:
    // TC-O(n*n)
    int tupleSameProduct(vector<int>& v) {
        int n = v.size();
        map<int, int> products;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                products[v[i]*v[j]]++;
            }
        }
        int cnt = 0;
        for(auto &it:products)
        {
            int x = it.second;
            if(it.second>1)  
            {
               cnt += (x*(x-1))/2; 
            }
        }
        return 8*cnt;
    }
};