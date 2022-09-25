class FrontMiddleBackQueue {
    //Using 2 dequeus, for first half and second half..
    //Always make sure that size of [deq1 = deq2] or [deq1 == deq2.size()-1];
    //push middle element in deq1 always..
private:
    void makeDeque1_LessThanEqual_2(deque<int> &deq1, deque<int> &deq2)
    {
        while(deq1.size() > deq2.size())
        {
            deq2.push_front(deq1.back());
            deq1.pop_back();
        }
        while(deq2.size()-deq1.size()>1)
        {
            deq1.push_back(deq2.front());
            deq2.pop_front();
        }
    }
public:
    
    deque<int> deq1, deq2;
    int x;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        deq1.push_front(val);
    }
    
    void pushMiddle(int val) {
        makeDeque1_LessThanEqual_2(deq1, deq2);
        deq1.push_back(val);
    }
    
    void pushBack(int val) {
        deq2.push_back(val);
    }
    
    int popFront() {
        if(deq1.size() == 0 and deq2.size() == 0)   return -1;
        
        if(deq1.size()!=0)
        {
            x = deq1.front();
            deq1.pop_front();
        }
        else
        {
            x = deq2.front();
            deq2.pop_front();
        }
        return x;
    }
    
    int popMiddle() {
        if(deq1.size() == 0 and deq2.size() == 0)   return -1;
        
        makeDeque1_LessThanEqual_2(deq1, deq2);
        if(deq1.size()==0 or deq1.size() < deq2.size()) 
        {
            x = deq2.front();
            deq2.pop_front();
        }
        else
        {
            x = deq1.back();
            deq1.pop_back();
        }
        return x;
    }
    
    int popBack() {
        if(deq1.size() == 0 and deq2.size() == 0)   return -1;
        if(deq2.size()!=0) 
        {
            x = deq2.back();
            deq2.pop_back();
        }
        else
        {
            x = deq1.back();
            deq1.pop_back();
        }
        return x;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */