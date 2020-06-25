int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size();
    if (n <= 2)
        return n;
    int ptr1 = 0;
    int ptr2 = 1;
    
    while (ptr2 < n) {
        if (A[ptr1] == A[ptr2]) {
            if (ptr1-1 >= 0 && A[ptr1-1] == A[ptr1]) {
                ptr2++;
            } else {
                A[ptr1+1] = A[ptr2];
                ptr1++;
                ptr2++;
            }
        } else {
            A[ptr1+1] = A[ptr2];
            ptr1++;
            ptr2++;
        }
    }
    return ptr1+1;
    
}

