vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    std::vector<int> output;
    int ptr1 = 0;
    int ptr2 = 0;
    
    int n1 = A.size();
    int n2 = B.size();
    
    while (ptr1 < n1 && ptr2 < n2) {
        if (A[ptr1] == B[ptr2]) {
            output.push_back(A[ptr1]);
            ptr1++;
            ptr2++;
        } else if (A[ptr1] > B[ptr2]) {
            ptr2++;
        } else {
            ptr1++;
        }
    }
    
    return output;
}

