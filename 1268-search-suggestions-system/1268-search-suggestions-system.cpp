class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
        sort(products.begin(), products.end());

        vector<vector<string>> res(searchWord.size());
        map<string, vector<int>> map;
        for(int i=0; i<n; i++)
        {
            string str = products[i];
            string temp = "";
            for(char c:str)
            {
                temp += c;
                map[temp].push_back(i);
            }
        }
        string temp="";
        for(int i=0; i<searchWord.size(); i++)
        {
            temp+=searchWord[i];
            int cnt=0;
            if(map.find(temp)!=map.end())
            {
                for(auto ind:map[temp])
                {
                    res[i].push_back(products[ind]);
                    cnt++;
                    if(cnt==3)  break;
                }
            }
            
        }
        return res;
    }
};