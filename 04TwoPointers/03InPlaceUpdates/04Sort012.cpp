void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void Solution::sortColors(vector<int> &A) {

    int ptr1 = 0;
    int ptr2 = A.size()-1;
    int i = 0;
    
    while (i <= ptr2) {
        if (A[i] == 0) {
            swap(A[i], A[ptr1]);
            ptr1++;
            i++;
        } else if (A[i] == 1) {
            i++;
        } else {
            swap(A[i], A[ptr2]);
            ptr2--;
        }
    }
}

