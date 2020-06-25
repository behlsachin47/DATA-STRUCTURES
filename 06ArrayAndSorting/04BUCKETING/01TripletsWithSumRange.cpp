int Solution::solve(vector<string> &A) {
    float a = std::stof(A[0]);
    float b = std::stof(A[1]);
    float c = std::stof(A[2]);
    
    if (a + b + c > 1 && a + b + c < 2) {
        return 1;
    } else {
        for (int i = 3; i < A.size(); i++) {
            if (a+b+c > 1) {
                if (a == std::max(a, std::max(b, c))) {
                    a = std::stof(A[i]);
                } else if (b == std::max(a, std::max(b, c))) {
                    b = std::stof(A[i]);
                } else {
                    c = std::stof(A[i]);
                }
                
            } else {
                if (a == std::min(a, std::min(b, c))) {
                    a = std::stof(A[i]);
                } else if (b == std::min(a, std::min(b, c))) {
                    b = std::stof(A[i]);
                } else {
                    c = std::stof(A[i]);
                }
            }
            
            
            if (a + b + c > 1 && a + b + c < 2) {
                return 1;
            }
        }
    }
    
    return 0;
}

