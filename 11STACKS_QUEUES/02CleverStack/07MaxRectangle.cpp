int getLargestArea(std::vector<int>& vec) {
    //get greater elem left side
    //get greater elem Right side
    std::vector<int> leftSmallerElem;
    std::vector<int> rightSmallerElem;
    std::stack<int> stack1;
    
    for (int i = 0; i < vec.size(); i++) {
        if (stack1.empty()) {
            leftSmallerElem.push_back(-1);
            stack1.push(i);
        } else if (!stack1.empty() && vec[stack1.top()] < vec[i]) {
            leftSmallerElem.push_back(stack1.top());
            stack1.push(i);
        } else {
            while (!stack1.empty() && vec[stack1.top()] >= vec[i]) {
                stack1.pop();
            }
            i--;
        }
    }
    
    stack1 = std::stack<int> ();
    for (int i = vec.size()-1; i >= 0; i--) {
        if (stack1.empty()) {
            rightSmallerElem.push_back(vec.size());
            stack1.push(i);
        } else if (!stack1.empty() && vec[stack1.top()] < vec[i]) {
            rightSmallerElem.push_back(stack1.top());
            stack1.push(i);
        } else {
            while (!stack1.empty() && vec[stack1.top()] >= vec[i]) {
                stack1.pop();
            }
            i++;
        }
    }
    std::reverse(rightSmallerElem.begin(), rightSmallerElem.end());
    /*
    for (int i = 0; i < vec.size(); i++) {
        std::cout << rightSmallerElem[i] << " ";
    }
    
    for (int i = 0; i < vec.size(); i++) {
        std::cout << leftSmallerElem[i] << " ";
    }
    */
    
    int ans = 0;
    
    for (int i = 0; i < vec.size(); i++) {
        int width = i - leftSmallerElem[i];
        width += rightSmallerElem[i] - i;
        width--;
        
        ans = std::max(ans, width* vec[i]);
    }
    
    return ans;
}
int Solution::solve(vector<vector<int> > &A) {
    //process to historgram
    int n = A.size();
    int m = A[0].size();
    bool debug = 0;
    
    
    std::vector<std::vector<int> > histogram(n, std::vector<int> (m, 0));
    
    for (int i = 0; i < A.size(); i++) {
        if (i == 0) {
            for (int j = 0; j < m; j++)
                histogram[i][j] = A[i][j];
        } else {
            
            for (int j = 0; j < A[i].size(); j++) {
                if (A[i][j] != 0) {
                    histogram[i][j] = histogram[i-1][j] + A[i][j];
                } 
            }
        }
    }
    if (debug)
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            std::cout << histogram[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int smallAns = getLargestArea(histogram[i]);
        ans = std::max(ans, smallAns );
        if (debug)
            std::cout << smallAns << std::endl;
    }
    
    return ans;
    
    
}
