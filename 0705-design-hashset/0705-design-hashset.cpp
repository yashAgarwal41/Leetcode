class MyHashSet {
public:
    int n;
    vector<list<int>> v;
    MyHashSet() {
        n = 100;
        v.resize(n);
    }
    
    int hash(int key){
        return key%n;
    }
    void add(int key) {
        int i = hash(key);
        auto it = find(v[i].begin(), v[i].end(), key);
        if(it == v[i].end())    v[i].push_back(key);
    }
    
    void remove(int key) {
        int i = hash(key);
        auto it = find(v[i].begin(), v[i].end(), key);
        if(it != v[i].end())    v[i].erase(it);
    }
    
    bool contains(int key) {
        int i = hash(key);
        auto it = find(v[i].begin(), v[i].end(), key);
        if(it != v[i].end())    return true;
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */