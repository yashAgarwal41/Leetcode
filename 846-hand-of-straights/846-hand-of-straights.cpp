class Solution {
public:
    //TC_O(nlogn)..
    bool isNStraightHand(vector<int>& v, int k) {
        int n = v.size();
        if(n%k) return false;
        map<int, int> map;
        for(auto i:v)   map[i]++;
        
        for(auto &it:map)
        {
            int freq = it.second;
            if(freq==0) continue;
            for(int i=0; i<k; i++)
            {
                if(map[it.first+i]<freq)
                    return false;
                else map[it.first+i] -= freq;
            }
        }
        return true;
    }
};