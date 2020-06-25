
int Solution::removeElement(vector<int> &A, int B) {
 
    int ptr1 = 0;
    int ptr2 = 0;
    while (ptr2 < A.size()) {
        if (A[ptr2] == B) {
            ptr2++;
        } else {
            A[ptr1++] = A[ptr2++];
        }
    }
    return ptr1;
}
