class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='V')   ans+=5;
            else if(s[i]=='L')  ans+=50;
            else if(s[i]=='D')  ans+=500;
            else if(s[i]=='M')  ans+=1000;
            else if(s[i]=='I')
            {
                if(i!=n-1)
                {
                    if(s[i+1]=='V') ans+=4;
                    else if(s[i+1]=='X')    ans+=9;
                    else {
                        ans+=1;
                        continue;
                    }
                    i++;
                }
                else ans+=1;
                
            }
            else if(s[i]=='X')
            {
                if(i!=n-1)
                {
                    if(s[i+1]=='L') ans+=40;
                    else if(s[i+1]=='C')    ans+=90;
                    else {
                        ans+=10;
                        continue;
                    }
                    i++;
                }
                else ans+=10;
                
            }
            else if(s[i]=='C')
            {
                if(i!=n-1)
                {
                    if(s[i+1]=='D') ans+=400;
                    else if(s[i+1]=='M')    ans+=900;
                    else {
                        ans+=100;
                        continue;
                    }
                    i++;
                }
                else ans+=100;
                
            }
        }
        return ans;
        
    }
};