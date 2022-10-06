class StockPrice {
public:
    multiset<int> set;
    map<int, int> map;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(map.find(timestamp) != map.end())
        {
            int old = map[timestamp];
            auto it = set.find(old);
            set.erase(it);
        }
        map[timestamp] = price;
        set.insert(price);
    }
    
    int current() {
        auto it = map.end();
        it--;
        return it->second;
    }
    
    int maximum() {
        auto it = set.end();
        it--;
        return *it;
    }
    
    int minimum() {
        return *(set.begin());
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */