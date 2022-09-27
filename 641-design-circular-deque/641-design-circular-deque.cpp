class MyCircularDeque {
private:
    vector<int> arr;
    int n, front, rear=0, cnt=0;
public:
    MyCircularDeque(int k) {
        n = k;
        front = n-1;
        for(int i=0; i<n; i++)  arr.push_back(-1);
    }
    
    bool insertFront(int value) {
        if(cnt==n)  return false;
        arr[front] = value;
        front--, cnt++;
        if(front<0) front = n-1;
        return true;
    }
    
    bool insertLast(int value) {
        if(cnt==n)  return false;
        arr[rear] = value;
        rear++, cnt++;
        if(rear==n) rear=0;
        return true;
    }
    
    bool deleteFront() {
        if(cnt==0)  return false;
        front++, cnt--;
        if(front==n)    front=0;
        arr[front] = -1;
        return true;
    }
    
    bool deleteLast() {
        if(cnt==0)  return false;
        rear--, cnt--;
        if(rear<0)  rear=n-1;
        arr[rear] = -1;
        return true;
    }
    
    int getFront() {
        if(cnt==0)  return -1;
        return arr[(front+1)%n];
    }
    
    int getRear() {
        if(cnt==0)  return -1;
        int r = rear-1;
        if(r<0) r = n-1;
        return arr[r];
        
    }
    
    bool isEmpty() {
        return cnt==0;
    }
    
    bool isFull() {
        return cnt==n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */