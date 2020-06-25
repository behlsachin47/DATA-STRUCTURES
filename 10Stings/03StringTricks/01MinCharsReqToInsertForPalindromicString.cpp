

int Solution::solve(string A) {
    std::string reverseA = A;
    std::reverse(reverseA.begin(), reverseA.end());
    std::vector<int> lps (A.size(), 0);
    A += "$";
    A += reverseA;
    int ptr1 = 0;
    int ptr2 = 0;
    for (; ptr2 < A.size(); ) {
        if (A[ptr1] == A[ptr2]) {
            lps[ptr2] = ptr1+1;
            ptr1++;
            ptr2++;
        } else if (ptr1 == 0) {
            lps[ptr2] = 0;
            ptr2++;
        } else {
            ptr1 = lps[ptr1-1];
        }
    }
    
    return A.size()-lps[A.size()-1];
}















int Solution::solve(string A) {
    int ptr1 = 0;
    int ptr2 = A.size()-1;
    int lastIndexOfPalindromicString = A.size()-1;    
    while (ptr1 < ptr2) {
        if (A[ptr1] != A[ptr2]) {
            ptr1 = 0;
            ptr2 = lastIndexOfPalindromicString-1;
            lastIndexOfPalindromicString--;
        } else {
            ptr1++;
            ptr2--;
        }
    }
    
    return A.size() - 1 - lastIndexOfPalindromicString;
}
