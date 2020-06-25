/*

Given two strings A and B. Each string represents an expression consisting of lowercase english alphabets, '+', '-', '(' and ')'.

The task is to compare them and check if they are similar. If they are similar return 1 else return 0.

NOTE: It may be assumed that there are at most 26 operands from ‘a’ to ‘z’ and every operand appears only once

*/












int Solution::solve(vector<int> &A) {
    std::vector<int> leftGreaterElem;
    std::vector<int> rightGreaterElem;
    std::stack<int> stack1;
    //basically have to maintain the elements in the stack in decreasing order
    for (int i = 0; i < A.size(); i++) {
        
            if (!stack1.empty() && A[stack1.top()] > A[i]) {
                leftGreaterElem.push_back(stack1.top());
                stack1.push(i);
            } else if (!stack1.empty()) {
                while (!stack1.empty() && A[stack1.top()] <= A[i]) {
                    stack1.pop();
                }
                i--;
            } else {
                leftGreaterElem.push_back(-1);
                stack1.push(i);
            }
        
    }
    
    stack1 = std::stack<int> ();
    for (int i = A.size()-1; i >= 0; i--) {
        if (!stack1.empty() && A[stack1.top()] > A[i]) {
            rightGreaterElem.push_back(stack1.top());
            stack1.push(i);
        } else if (!stack1.empty()) {
            while (!stack1.empty() && A[stack1.top()] <= A[i]) {
                stack1.pop();
            }
            i++;
        } else {
            rightGreaterElem.push_back(-1);
            stack1.push(i);
        }
    }
    
    std::reverse(rightGreaterElem.begin(), rightGreaterElem.end());
    int ans = 0;
    for (int i = 0; i < A.size(); i++) {
        if (leftGreaterElem[i] != -1) {
            ans = std::max(ans, A[i] ^ A[leftGreaterElem[i]]);
        } 
        
        if (rightGreaterElem[i] != -1) {
            ans = std::max(ans, A[i] ^ A[rightGreaterElem[i]]);
        }
    }
    return ans;
}
