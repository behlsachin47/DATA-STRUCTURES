int Solution::evalRPN(vector<string> &A) {
    std::stack<std::string> stackOperands;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/") {
            int num1, num2, result;
            if (stackOperands.size()) {
                num2 = std::stoi(stackOperands.top());
                stackOperands.pop();
            } else {
                std::cout << "ERROR\n";
                return 0;
            }
            
            if (stackOperands.size()) {
                num1 = std::stoi(stackOperands.top());
                stackOperands.pop();
            } else {
                std::cout << "ERROR\n";
                return 0;
            }
            
            if (A[i] == "+") {
                result = num1 + num2;
            } else if (A[i] == "-") {
                result = num1 - num2;
            } else if (A[i] == "/") {
                result = num1/num2;
            } else {
                result = num1 * num2;
            }
            
            stackOperands.push(std::to_string(result));
        } else {
            stackOperands.push(A[i]);
        }
    }
    
    if (stackOperands.size() != 1) 
        return 0;
    
    return std::stoi(stackOperands.top());
}