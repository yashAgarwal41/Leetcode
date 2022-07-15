class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size(), l=0, r=0, sp=0;
        for(int i=0; i<n; i++)
        {
            if(start[i]=='L')   l++;
            if(start[i]=='R')   r++;
            if(start[i]=='_')   sp++;
        }
        for(int i=0; i<n; i++)
        {
            if(target[i]=='L')   l--;
            if(target[i]=='R')   r--;
            if(target[i]=='_')   sp--;
        }
        if(l!=0 or r!=0 or sp!=0) return false;
        for(int i=0; i<n; i++)
        {
            if(start[i]=='L')
            {
                if(r>0) return false;
                l++;
            }
            if(start[i]=='R')
                r++;
            if(target[i]=='L')
                l--;
            if(target[i]=='R')
                r--;
            if(r<0 or l>0)  return false;
            if(r>0 and l<0) return false;
        }
        return true;
    }
};