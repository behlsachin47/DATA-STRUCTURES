bool isOverFlow(int digit, int num) {
    
    if (num >= 0) {
        if (num > (INT_MAX/10)) {
            return 1;
        }
        else if ((num == (INT_MAX/10)) && digit > num) {
            return 1;
        }
    } else {
        if (num < INT_MIN/10)
            return 1;
        else if (num == (INT_MIN/10) && digit > num)
            return 1;
    }
    return 0;
}


bool isNumeric(char ch) {
    if (ch >= '0' && ch <= '9')
        return 1;
    return 0;
}
int Solution::atoi(const string A) {
    int num = 0;
    int firstIndex = 0;
    bool isNeg = 0;
    if (A[0] == '+')
        firstIndex++;
    else if (A[0] == '-') {
        firstIndex++;
        isNeg = true;
    }
    
    for (int i = firstIndex; i < A.size() && isNumeric(A[i]); i++) {
        
        int digit = A[i] - '0';
        if (isOverFlow(digit, num)) {
            if (isNeg)
                return INT_MIN;
            else
                return INT_MAX;
        }
        
        if (isNeg) {
            num = num*10 - digit;    
        } else {
            num = num*10 + digit;
            
           
        }
    }
    
    return num;
}
