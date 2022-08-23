class RangeFreqQuery {
public:
    //HashMap..TC-O(n + logn)..
    unordered_map<int, vector<int>> map;
    
    //TC-O(n)..
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0; i<arr.size(); i++)
        {
            map[arr[i]].push_back(i);
        }
    }
    
    //TC-O(logn)..
    int query(int left, int right, int value) {
        auto it = map.find(value);
        if(it == map.end())
            return 0;
        int lb = lower_bound(it->second.begin(), it->second.end(), left) - it->second.begin();
        int ub = upper_bound(it->second.begin(), it->second.end(), right) - it->second.begin();
        
        return ub-lb;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */