class MyStack {
public:
    //make either of push or pop costly :)
    std::queue<int> q1;
    std::queue<int> q2;
    int topElm = -1;
    
    MyStack() {
        //nothing as such is required here     
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (q1.empty()) {
            q2.push(x);
        } else {
            q1.push(x);
        }
        topElm = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (MyStack::empty())
            return -1;
        
        topElm = -1;
        int ans = -1;
        if (q1.empty()) {
            while (q2.size() != 1) {
                q1.push(q2.front());
                topElm = q2.front();
                q2.pop();
            }    
            ans = q2.front();
            q2.pop();
        } else {
            while (q1.size() != 1) {
                q2.push(q1.front());
                topElm = q1.front();
                q1.pop();
            }
            ans = q1.front();
            q1.pop();
        }
        
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        return topElm;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if (q1.empty() && q2.empty())
            return 1;
        return 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */