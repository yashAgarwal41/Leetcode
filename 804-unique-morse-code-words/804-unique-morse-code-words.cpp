class Solution {
public:
    string transform[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    int uniqueMorseRepresentations(vector<string>& words) {
        int n = words.size();
        set<string> set;
        for(auto &str:words)
        {
            string code = "";
            for(auto &c:str)
            {
                code += transform[c-'a'];
            }
            set.insert(code);
        }
        return set.size();
    }
};