class Solution {
public:
    int removeElement(vector<int>& v, int val) {
        int n = v.size(), cnt = 0;
        for(auto c:v)
        {
            if(c == val) cnt++;
        }
        int i = 0, j = n-1;
        while(j>=n-cnt)
        {
            if(v[j] == val) j--;
            else if(v[i] == val)
            {
                swap(v[i], v[j]);
                j--; i++;
            }
            else i++;
        }
        return n-cnt;
    }
};