class MyCircularQueue {
public:
    int cnt, first, last, n;
    vector<int> arr;
    MyCircularQueue(int k) {
        n = k;      //size of the queue -> k
        cnt = 0;    //current size of queue..
        first=0;    //start pointer of the queue..
        last=0;     //last pointer of the queue..
        for(int i=0; i<n; i++)  arr.push_back(-1);
    }
    
    bool enQueue(int value) {
        if(cnt == n)    return false;
        arr[last%n] = value;
        last++;
        cnt++;
        return true;
    }
    
    bool deQueue() {
        if(cnt == 0)    return false;
        arr[first%n] = -1;
        first++;
        cnt--;
        return true;
    }
    
    int Front() {
        if(cnt == 0)    return -1;
        return arr[first%n];
    }
    
    int Rear() {
        if(cnt == 0)    return -1;
        return arr[(last-1)%n];
    }
    
    bool isEmpty() {
        if(cnt == 0)    return true;
        return false;
    }
    
    bool isFull() {
        if(cnt == n)    return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */