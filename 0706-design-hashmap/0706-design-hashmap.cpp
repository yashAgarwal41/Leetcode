class MyHashMap {
public:
    int n;
    vector<vector<pair<int, int>>> v;
    MyHashMap() {
        n = 1000;
        v.resize(n);
    }
    
    int hash(int key){
        return key%n;
    }
    
    void put(int key, int value) {
        int i = hash(key);
        auto it = v[i].begin();
        while(it!=v[i].end())
        {
            if(it->first == key){
                it->second = value;
                return;
            }
            it++;
        }
        v[i].push_back({key, value});
    }
    
    int get(int key) {
        int i = hash(key);
        auto it = v[i].begin();
        while(it!=v[i].end())
        {
            if(it->first == key) return it->second;
            it++;
        }
        return -1;
    }
    
    void remove(int key) {
        int i = hash(key);
        auto it = v[i].begin();
        while(it!=v[i].end())
        {
            if(it->first == key) 
            {
                it->second = -1;
                return;
            }
            it++;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */