class Solution {
public:
    //TC-O(n), SC-O(n)..
    //PreCalculate:
    //distance of nearest 'R' at left side if no 'L' comes between..
    //distance of nearest 'L' at right side if no 'R' comes between..
    //if both distance are same, then it will not bend
    //else take the min distance direction which make it fall first..
    //distance = 0 means, that it is not fallen by domino
    
    string pushDominoes(string s) {
        int n = s.size();
        vector<int> rightDis(n, 0), leftDis(n, 0);
        int dis=0, found=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='L')   dis=0, found=0;
            else if(s[i]=='R')   dis=0, found=1;
            else if(found==1) dis++;
            rightDis[i] = dis;
        }
        dis=0, found=0;
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]=='R')   dis=0, found=0;
            else if(s[i]=='L')   dis=0, found=1;
            else if(found==1) dis++;
            leftDis[i] = dis;
        }
        
        for(int i=0; i<n; i++)
        {
            if(leftDis[i] == rightDis[i])   continue;
            if(leftDis[i] == 0 or rightDis[i] == 0)
                s[i] = leftDis[i] == 0 ? 'R' : 'L';
            else
                s[i] = min(leftDis[i], rightDis[i]) == leftDis[i] ? 'L' : 'R';
        }
        return s;
    }
};