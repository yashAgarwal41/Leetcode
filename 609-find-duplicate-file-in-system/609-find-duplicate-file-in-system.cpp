class Solution {
public:
    void pushFiles(string &path, unordered_map<string, vector<string>> &map)
    {
        int pos = path.find(" ");   
        string directory_path = path.substr(0, pos);  //selecting directory name..
        string file = directory_path + "/";
        string content = "";
        for(int j = pos+1; j<path.size(); j++)
        {
            //creating content..
            if(path[j] == '(')
            {
                j++;
                while(path[j]!=')')
                    content += path[j++];
                j++;
            }
            //inserting into map..
            if(path[j] == ' ')
            {
                map[content].push_back(file); 
                content = "";
                file = directory_path + "/";
                continue;
            }
            file += path[j];
        }
        map[content].push_back(file); 
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int n = paths.size();
        unordered_map<string, vector<string>> map;
        
        for(auto &str : paths)
        {
            pushFiles(str, map);
        }
        
        vector<vector<string>> res;
        for(auto &it : map) 
        {
            if(it.second.size()>1)  res.push_back(it.second);
        }
        return res;
    }
};