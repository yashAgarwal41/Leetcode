class Solution {
public:
    //max_distance covered by an ant without changing direction.
    //Hint- think of swapping ants on collision with each other
    //like  _   _   _   _   _
    //      A->           <-B
    //      _   _  <-A  _   _
    //      _   _  B->  _   _
    //now instead swap each other like and think that don't collide, instead surpass each other
    //      _   _  <-B  _   _
    //      _   _  A->  _   _
    //    <-B   _   _   _   A->
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l = 0, r=0;
        if(left.size()) 
            l = *max_element(left.begin(), left.end()) - 0;
        if(right.size())
            r = n - *min_element(right.begin(), right.end());
        
        return max(l, r);
    }
};