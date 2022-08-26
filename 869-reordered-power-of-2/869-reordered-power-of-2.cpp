class Solution {
public:
    //TC-O(9*logn)
    bool reorderedPowerOf2(int n) {
        int freq[10] = {0};
        while(n>0)
        {
            freq[n%10]++;
            n/=10;
        }
        int p=0, x=1;
        while(p<30)
        {
            int cnt[10]={0};
            int temp = x;
            while(temp>0)
            {
                cnt[temp%10]++;
                temp/=10;
            }
            bool found=true;
            for(int i=0; i<=9; i++)
            {
                if(freq[i] != cnt[i])
                {
                    found = false;
                    break;
                }
            }
            if(found)   return true;
            
            x*=2;
            p++;
        }
        return false;
    }
};