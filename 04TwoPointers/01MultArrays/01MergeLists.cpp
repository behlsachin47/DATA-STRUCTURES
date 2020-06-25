void Solution::merge(vector<int> &A, vector<int> &B) {
    int n1 = A.size();
    int n2 = B.size();
    
    int ptr1 = n1-1;
    int ptr2 = n2-1;
    int ptr = n1+n2-1;
    for (int i = 0; i < n2; i++)
        A.push_back(0);
    
    while (ptr1 >= 0 && ptr2 >= 0) {
        if (A[ptr1] < B[ptr2]) {
            A[ptr] = B[ptr2];
            ptr2--;
        } else {
            A[ptr] = A[ptr1];
            ptr1--;
        }
        ptr--;
    }
    
    while (ptr1 >= 0) {
        A[ptr] = A[ptr1];
        ptr1--;
        ptr--;
    }
    
    while (ptr2 >= 0) {
        A[ptr] = B[ptr2];
        ptr2--;
        ptr--;
    }
    
}

