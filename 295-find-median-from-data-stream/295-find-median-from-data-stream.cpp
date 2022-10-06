//Policy-Based Data Structure..
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
//  find_by_order, order_of_key
class MedianFinder {
public:
    int n = 0;
    pbds set;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        set.insert(num);
        n++;
    }
    
    double findMedian() {
        if(n%2)
        {
            auto it = set.find_by_order(n/2);
            return *it;
        }
        else 
        {
            auto it1 = set.find_by_order((n/2)-1);
            auto it2 = set.find_by_order(n/2);
            double ans = (*it1 + *it2)/2.0;
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */