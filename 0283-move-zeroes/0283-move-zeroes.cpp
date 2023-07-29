class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int n = v.size();
        int i=0, j=0, cnt=0;
        
        while(j<n)
        {
            if(v[j] == 0)    
            {
                j++, cnt++;
                continue;  
            }
            else 
            {
                v[i] = v[j];
                i++, j++;
            }
        }
        j=n-1;
        while(cnt--)
        {
            v[j--] = 0;
        }
        
    }
};