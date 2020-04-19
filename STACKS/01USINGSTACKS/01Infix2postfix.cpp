string Solution::solve(string A) {
    std::unordered_map<char, int> precedence;
    precedence.insert({'(',0});
    precedence.insert({'+', 1});
    precedence.insert({'-',1});
    precedence.insert({'*',2});
    precedence.insert({'/',2});
    precedence.insert({'^',3});
    stack<char> stack1;
    string result;
    
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == '*' || A[i] == '/' || A[i] == '+' || A[i] == '-' || A[i] == '(' || A[i] == ')' || A[i] == '^') {
            if (stack1.empty())
                stack1.push(A[i]);
            else if (A[i] == ')') {
                while (stack1.top() != '(') {
                    result += stack1.top();
                    stack1.pop();
                }
                stack1.pop();
            } else if (A[i] == '(') {
                stack1.push(A[i]);
            } else {
                while (stack1.empty() == false && precedence[stack1.top()] >= precedence[A[i]]) {
                    result += stack1.top();
                    stack1.pop();
                }
                stack1.push(A[i]);
            }
        } else {
            result += A[i];
        }
    }
    while (stack1.empty() == false) {
        result += stack1.top();
        stack1.pop();
    }
    return result;
}
