class MinStack {
public:
    stack<int> st;
    map<int, int> map;
    
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        map[val]++;
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        map[val]--;
        if(map[val]==0)
            map.erase(val);     //TC-O(logn)..
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        auto it = map.begin();
        return it->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */