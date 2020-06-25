int Solution::largestRectangleArea(vector<int> &A) {
    if (A.size() == 0)
        return 0;
    
    
    std::stack<int> stack1;
    std::vector<int> leftSmallerIndex;
    std::vector<int> rightSmallerIndex;
    
    for (int i = 0; i < A.size(); i++) {
        if (stack1.empty()) {
            leftSmallerIndex.push_back(-1);
            stack1.push(i);
        } else if (A[stack1.top()] < A[i]) {
            leftSmallerIndex.push_back(stack1.top());
            stack1.push(i);
        } else {
            while (stack1.size() && A[stack1.top()] >= A[i]) {
                stack1.pop();
            }
            i--;
        }
    }
    
    stack1 = std::stack<int> ();
    for (int i = A.size()-1; i >= 0; i--) {
        if (stack1.empty()) {
            rightSmallerIndex.push_back(A.size());
            stack1.push(i);
        } else if (A[stack1.top()] < A[i]) {
            rightSmallerIndex.push_back(stack1.top());
            stack1.push(i);
        } else {
            while (stack1.size() && A[stack1.top()] >= A[i]) {
                stack1.pop();
            }
            i++;
        }
    }
    
    for (int i = 0; i < A.size(); i++) 
        std::cout << leftSmallerIndex[i] << " ";
    std::cout << std::endl;
    
    
    for (int i = 0; i < A.size(); i++) 
        std::cout << rightSmallerIndex[i] << " ";
    std::cout << std::endl;
    
    
    int ans = 0;
    for (int i = 0; i < A.size(); i++) {
        int width = rightSmallerIndex[i] - leftSmallerIndex[i] -1;
        ans = std::max(ans, width * A[i]);
    }
    return ans;
}
