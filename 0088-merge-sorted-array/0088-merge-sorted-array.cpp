class Solution {
public:
    void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
        int i = m-1, j = n-1, k = m+n-1;
        while(k>=0)
        {
            if(i>=0 and j>=0)
            {
                if(v1[i]<=v2[j])
                {
                    v1[k--]  = v2[j--];
                }
                else    v1[k--] = v1[i--]; 
            }
            else
            {
                if(i>=0)    v1[k--] = v1[i--];
                else v1[k--] = v2[j--];
            }
                
        }
    }
};