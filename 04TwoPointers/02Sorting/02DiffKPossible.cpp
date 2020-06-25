int Solution::diffPossible(vector<int> &A, int B) {
    int n = A.size();
    if (n < 2) 
        return 0;
    int ptr2 = 0;
    int ptr1 = 1;
    while (ptr1 < n) {
        if (A[ptr1] - A[ptr2] == B)
            return 1;
        else if (A[ptr1] - A[ptr2] > B) {
            ptr2++;
        } else {
            ptr1++;
        }
        
        if(ptr1 == ptr2)  {
            ptr1++;
        }
    }
    
    return 0;
}

