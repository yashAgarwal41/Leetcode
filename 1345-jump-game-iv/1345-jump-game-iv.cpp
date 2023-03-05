class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mmap;
        for(int i=0; i<n; i++)
        {
            mmap[arr[i]].push_back(i);
        }
        queue<int> q;   //contains indexes
        q.push(0);
        int steps = 0;
        while(!q.empty())
        {
            int sz = q.size();
            steps++;
            for(int i=0; i<sz; i++)
            {
                int j = q.front();
                if(j == n-1)    return steps-1;
                q.pop();
                
                if(j-1>=0 and mmap.find(arr[j-1]) != mmap.end())
                    q.push(j-1);
                if(j+1<n and mmap.find(arr[j+1]) != mmap.end())
                    q.push(j+1);
                for(auto &k : mmap[arr[j]])
                {
                    if(k == j)  continue;
                    q.push(k);
                }
                
                mmap.erase(arr[j]);
            }
        }
        return steps-1;
    }
};