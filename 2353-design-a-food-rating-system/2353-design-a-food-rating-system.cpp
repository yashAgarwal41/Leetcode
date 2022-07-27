class FoodRatings {
public:
    unordered_map<string, pair<string, int>> dish;
    // unordered_map<string, map<int, string>> cuis;
    unordered_map<string, set<pair<int, string>>> mmap;
    
    int n;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        n = foods.size();
        for(int i=0; i<n; i++)
        {
            dish[foods[i]] = {cuisines[i], ratings[i]};
            // cuis[cuisines[i]].insert(make_pair(ratings[i], foods[i]));
            mmap[cuisines[i]].insert({-ratings[i], foods[i]});
        }
        
        // for(auto &it:cuis)
        // {
        //     cout<<it.first<<"->";
        //     // for(auto &it2:it.first)
        //         // cout<<it2.first<<" "<<it2.second<<endl;
        // }
        
    }
    
    void changeRating(string food, int newRating) {
        auto &cuisine = dish[food].first;
        auto &oldRating = dish[food].second;
        mmap[cuisine].erase({-oldRating, food});
        mmap[cuisine].insert({-newRating, food});
        auto &it = dish[food];
        it.second = newRating;
    }
    
    string highestRated(string cuisine) {
        auto it = mmap[cuisine].begin();
        return it->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */