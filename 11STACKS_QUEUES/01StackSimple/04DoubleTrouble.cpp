string Solution::solve(string A) {
    std::stack<char> stack1;
    for (int i = 0; i < A.size(); i++) {
        if (stack1.empty() == false && A[i] == stack1.top()) {
            stack1.pop();
        } else {
            stack1.push(A[i]);
        }
    }
    
    std::string res;
    while (!stack1.empty()) {
        res += stack1.top();
        stack1.pop();
    }
    
    std::reverse(res.begin(), res.end());
    
    return res;
}
