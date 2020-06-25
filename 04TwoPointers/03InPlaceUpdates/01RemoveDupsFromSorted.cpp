int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size();
    if (n <= 1)
        return n;
    
    int ptr1 = 0;
    int ptr2 = 1;
    while (ptr2  < n) {
        if (A[ptr1] == A[ptr2])
            ptr2++;
        else {
            A[ptr1+1] = A[ptr2];
            ptr2++;
            ptr1++;
        }
    }
    return ptr1+1;
}
