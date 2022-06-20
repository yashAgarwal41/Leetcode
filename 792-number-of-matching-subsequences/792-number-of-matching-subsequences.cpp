class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size(), ans=0;
        map<char, vector<int>> map;
        for(int i=0; i<n; i++)
        {
            map[s[i]].push_back(i);
        }
        
        for(int i=0; i<words.size(); i++)
        {
            string str = words[i];
            int ind=0, ch=1;
            for(int k=0; k<str.size(); k++)
            {
                auto it = map.find(str[k]);
                if(it==map.end())   
                {
                    ch=0;
                    break;
                }
                int temp = lower_bound(it->second.begin(), it->second.end(), ind) - it->second.begin();
                if(temp>=it->second.size())
                {
                    ch=0;   break;
                }
                temp = it->second[temp];
                ind = temp+1;
            }
            if(ch)  
            {
                ans++;
            }
        }
        cout<<endl;
        return ans;
    }
};