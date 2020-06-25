vector<int> Solution::solve(vector<int> &A) {
    std::stack<int> stack1;
    std::stack<int> stack2;
    
    for(int i = 0; i < A.size(); i++) {
        if (stack1.empty()) {
            stack1.push(A[i]);
        } else if (stack1.top() >= A[i]) {
            stack1.push(A[i]);
        } else {
            while (stack1.empty() == false && stack1.top() <A[i]) {
                stack2.push(stack1.top());
                stack1.pop();
            }
            
            stack1.push(A[i]);
            
            while(stack2.empty() == false) {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
    }
    
    std::vector<int> out;
    while (stack1.empty() == false) {
        out.push_back(stack1.top());
        stack1.pop();
    }
    
    return out;
}
