class Solution {
public:
    //start from last, TC-O(n*10)
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int m=0, p=0, g=0;
        for(int i=n-1; i>=0; i--)
        {
            for(auto &c : garbage[i])
            {
                if(c == 'M')    m++;
                else if(c == 'P')   p++;
                else g++;
            }
            if(i>0)
            {
                if(m>0) m+=travel[i-1];
                if(p>0) p+=travel[i-1];
                if(g>0) g+=travel[i-1]; 
            }
        }
        return m+p+g;
        
    }
};