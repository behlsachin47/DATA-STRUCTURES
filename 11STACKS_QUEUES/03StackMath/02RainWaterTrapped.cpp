int Solution::trap(const vector<int> &A) {
    std::vector<int> leftMaximum;
    std::vector<int> rightMaximum;
    bool debug = 1;
    for (int i = 0; i < A.size(); i++) {
        if (i == 0) {
            leftMaximum.push_back(0);
        } else {
            leftMaximum.push_back(std::max(leftMaximum[i-1], A[i-1]));
        }
    }
    
    for (int i = A.size()-1; i >= 0; i--) {
        if (i == A.size()-1)
            rightMaximum.push_back(0);
        else {
            rightMaximum.push_back(std::max(rightMaximum.back(), A[i+1]));
        }
    }
    std::reverse(rightMaximum.begin(), rightMaximum.end());
    
    if (0) {
        for (int i = 0; i < A.size(); i++) 
            std::cout << leftMaximum[i] << " ";
        std::cout << std::endl;
        
        for (int i = 0; i < A.size(); i++)
            std::cout << rightMaximum[i] << " ";
        
        
        std::cout << std::endl;
    }
    int answer = 0;
    for (int i = 1; i < A.size()-1; i++) {
        answer += std::max(std::min(leftMaximum[i], rightMaximum[i]) - A[i], 0);
        
    }
    
    return answer;
}
