class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int n = v.size(), j=0, cnt=1;
        for(int i=1; i<n; i++)
        {
            if(v[i-1] == v[i])  cnt++;
            else 
            {
                for(int k=0; k<2 and cnt>0; k++, cnt--)
                {
                    v[j] = v[i-1];
                    j++;
                }
                cnt = 1;
            }
        }
        for(int k=0; k<2 and cnt>0; k++, cnt--)
        {
            v[j] = v[n-1];
            j++;
        }
        return j;
    }
};