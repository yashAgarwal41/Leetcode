class TimeMap {
public:
    unordered_map<string, set<pair<int, string>>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto lb = map[key].lower_bound({timestamp, ""});
        if(map[key].size()==0)  return "";
        if(lb->first == timestamp)  return lb->second;
        if(lb != map[key].begin())
        {
            lb--;
            return lb->second;
        }
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */