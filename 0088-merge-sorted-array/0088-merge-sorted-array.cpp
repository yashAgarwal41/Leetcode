class Solution {
public:
    void merge(vector<int>& v1, int m, vector<int>& v2, int n) 
    {
        int i=m-1, j = m+n-1, k = n-1;
        while(i>=0 and k>=0)
        {
            if(v1[i] <= v2[k])
                v1[j--] = v2[k--];
            else 
                v1[j--] = v1[i--];
        }
        while(i>=0)
            v1[j--] = v1[i--];
        
        while(k>=0)
            v1[j--] = v2[k--];
        
    }
};