class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        long long ans=0;
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        vector<pair<int, int>> vp;
        int i=0, j=0;
        while(i<n)
        {
            if(nums[i]%2)
            {
                while(j<n)
                {
                    if(target[j]%2)   
                    {
                        vp.push_back({nums[i], target[j]});
                        j++;
                        break;
                    }
                    j++;
                }
            }
            i++;
        }
        i=0, j=0;
        while(i<n)
        {
            if(nums[i]%2==0)
            {
                while(j<n)
                {
                    if(target[j]%2==0)   
                    {
                        vp.push_back({nums[i], target[j]});
                        j++;
                        break;
                    }
                    j++;
                }
            }
            i++;
        }
        sort(vp.begin(), vp.end());
        
        long long add = 0, sub = 0;
        
        for(int i=0; i<n; i++)
        {
            int x = vp[i].first, y = vp[i].second;
            if(x==y)    continue;
            long long cnt = abs(x-y)/2;
            if(x<y)
            {
                if(add>0)
                {
                    cnt -= min(cnt, add);
                    add -= min(cnt, add);
                }
                if(cnt>0)
                {
                    ans += cnt;
                    sub += cnt;
                }
            }
            else
            {
                if(sub>0)
                {
                    int t = min(cnt, sub);
                    cnt -= t;
                    sub -= t;
                }
                if(cnt>0)
                {
                    ans += cnt;
                    add += cnt;
                }
            }
        }
        
        return ans;
    }
};