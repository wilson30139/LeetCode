class MinStack {
private:
    stack<int> s;
    stack<int> minS;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        int sSize = s.size();
        s.push(value);
        if (sSize > 0) {
            if (value > minS.top())
                minS.push(minS.top());
            else
                minS.push(value);
        }
        else
            minS.push(value);
    }
    
    void pop() {
        s.pop();
        minS.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */