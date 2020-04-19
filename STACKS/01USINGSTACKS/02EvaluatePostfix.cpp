int Solution::evalRPN(vector<string> &A) {
    stack<int> stack1;
    
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == "*" || A[i] == "/" || A[i] == "-" || A[i] == "+") {
            int num2 = stack1.top();
            stack1.pop();
            int num1 = stack1.top();
            stack1.pop();
            int res;
            if (A[i] == "*") 
                res = num1* num2;
            else if (A[i] == "/")
                res = num1/num2;
            else if (A[i] == "+")
                res = num1 + num2;
            else if (A[i] == "-") 
                res = num1-num2;
            else {
                std::cerr << "INTERNAL ERROR";
                return -1;
            }
            stack1.push(res);
        } else {
            stack1.push(std::stoi(A[i]));
        } 
    }
    return stack1.top();
}
