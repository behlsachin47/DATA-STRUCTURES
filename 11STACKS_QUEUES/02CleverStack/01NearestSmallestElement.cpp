vector<int> Solution::prevSmaller(vector<int> &A) {
    std::vector<int> output;
    if (A.size() == 0)
        return output;
        
    std::stack<int> stack1;
    for (int i = 0; i < A.size(); i++) {
        if (stack1.empty()) {
            output.push_back(-1);
            stack1.push(A[i]);
        } else if (stack1.top() < A[i]) {
            output.push_back(stack1.top());
            stack1.push(A[i]);                        
        } else {
            while (stack1.empty() == false && stack1.top() >= A[i]) {
                stack1.pop();
            }
            i--;
        }
    }
    
    return output;
    
}