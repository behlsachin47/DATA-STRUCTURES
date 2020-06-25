string Solution::solve(string A) {
    std::unordered_map<char, int> precedenceMap;
    precedenceMap.insert({'(', 0});
    precedenceMap.insert({'^', 3});
    precedenceMap.insert({'/', 2});
    precedenceMap.insert({'*', 2});
    precedenceMap.insert({'+', 1});
    precedenceMap.insert({'-', 1});
    
    
    std::string output;
    std::stack<char> operatorStack;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != '(' && precedenceMap.count(A[i])) {
            if (operatorStack.empty()) {
                operatorStack.push(A[i]);
            } else {
                if (precedenceMap[operatorStack.top()] >= precedenceMap[A[i]]) {
                    while (!operatorStack.empty() && precedenceMap[operatorStack.top()] >= precedenceMap[A[i]]) {
                        output += operatorStack.top();
                        operatorStack.pop();
                    }
                    operatorStack.push(A[i]);
                } else {
                    operatorStack.push(A[i]);
                }
            }
        } else if (A[i] == '(') {
            operatorStack.push(A[i]);
            
        } else if (A[i] == ')') {
            while (operatorStack.top() != '(') {
                output += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();
            
        } else {
            output += A[i];
        }
    }
    
    while (!operatorStack.empty()) {
        output += operatorStack.top();
        operatorStack.pop();
    }
    return output;
}
