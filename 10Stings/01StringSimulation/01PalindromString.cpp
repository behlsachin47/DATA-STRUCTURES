bool isAlphaNumeric(char ch) {
    if (ch >= '0' && ch <= '9')
        return 1;
    
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 1;
    
    return 0;
}

int Solution::isPalindrome(string A) {
    int ptr1 = 0;
    int ptr2 = A.size()-1;
    
    while (ptr1 < ptr2) {
        bool bAlphaNumeric1 = isAlphaNumeric(A[ptr1]);
        bool bAlphaNumeric2 = isAlphaNumeric(A[ptr2]);
        
        if (bAlphaNumeric1 && bAlphaNumeric2) {
            if (std::tolower(A[ptr1]) != std::tolower(A[ptr2])) {
                return 0;
            }
            ptr1++;
            ptr2--;
        } else if (bAlphaNumeric1) {
            ptr2--;
        } else if (bAlphaNumeric2) {
            ptr1++;
        } else {
            ptr1++;
            ptr2--;
        }
    }
    return 1;
}
