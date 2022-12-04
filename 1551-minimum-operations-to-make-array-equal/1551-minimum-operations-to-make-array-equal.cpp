class Solution {
public:
    //Math - TC-O(1), SC-O(1)..
    //convert all into median..
    int minOperations(int n) {
        int m = n/2;
        if(n%2==0)  return m*m;
        else return m*(m+1);
    }
};

//n-even:  1, 3, 5, 7, 9, 11
//final:   6, 6, 6, 6, 6, 6
//convert:+5,+3,+1,-1,-3,-5
//operations: 1+3+5

