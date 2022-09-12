class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int i = 0, j = n-1, score = 0;
        int maxi = 0;
        while(i<=j)
        {
            if(power >= tokens[i])
            {
                power -= tokens[i];
                i++, score++;
                maxi = max(maxi, score);
            }
            else if(score > 0)
            {
                power += tokens[j];
                j--, score--;
            }
            else break;
        }
        return maxi;
    }
};