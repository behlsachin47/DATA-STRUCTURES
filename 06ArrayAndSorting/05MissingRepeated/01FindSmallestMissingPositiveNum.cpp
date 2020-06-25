int Solution::firstMissingPositive(vector<int> &A) {
    int limit = A.size()-1;
    for (int i = 0; i <= limit; ) {
        if (A[i] < 0) {
            swap(A[i], A[limit]);
            limit--;
        } else {
            i++;
        }
    }
   
    int ans;
    for (int i = 0; i <= limit; i++) {
        int num = abs(A[i]);
        int index = num-1;
        if (index > limit) {
            continue;
        } else {
            if (A[index] > 0) {
                A[index] *= -1;
            }
        }
    }
    
    for (int i = 0; i <= limit; i++) {
        if (A[i] > 0) {
            return i+1;
        }
    }
    return limit+2;
}

