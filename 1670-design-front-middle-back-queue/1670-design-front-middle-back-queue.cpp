class FrontMiddleBackQueue {
public:
    deque<int> deq1, deq2;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        deq1.push_front(val);
    }
    
    void pushMiddle(int val) {
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
        deq1.push_back(val);
    }
    
    void pushBack(int val) {
        deq2.push_back(val);
    }
    
    int popFront() {
        if(deq1.size() == 0 and deq2.size() == 0)   return -1;
        
        if(deq1.size()!=0)
        {
            int x = deq1.front();
            deq1.pop_front();
            return x;
        }
        else
        {
            int x = deq2.front();
            deq2.pop_front();
            return x;
        }
    }
    
    int popMiddle() {
        if(deq1.size() == 0 and deq2.size() == 0)   return -1;
        
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
        
        if(deq1.size()==0 or deq1.size() < deq2.size()) 
        {
            int x = deq2.front();
            deq2.pop_front();
            return x;
        }
        else
        {
            int x = deq1.back();
            deq1.pop_back();
            return x;
        }
    }
    
    int popBack() {
        if(deq1.size() == 0 and deq2.size() == 0)   return -1;
        if(deq2.size()!=0) 
        {
            int x = deq2.back();
            deq2.pop_back();
            return x;
        }
        else
        {
            int x = deq1.back();
            deq1.pop_back();
            return x;
        }
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