int Solution::solve(vector<int> &A) {
    int n = A.size();
    int low = 0;
    int high = n-1;
    
    while (low <= high) {
        int mid = low + (high-low)/2;
        bool isPeak = 1;
        bool flag1 = 0;
        bool flag2 = 0;
        
        if (mid-1 >= 0 && A[mid] < A[mid-1] ) {
            flag1 = 1;
            isPeak = 0;
        }
        
        if (mid+1 < n && A[mid] < A[mid+1]) {
            flag2 = 1;
            isPeak = 0;
        }
            
        if (isPeak) 
            return A[mid];
        else if (flag1 && flag2) {
            low = mid+1;
        } else if (flag1) {
            high = mid-1;
        } else {
            low = mid+1;
        }
        
    }
    
    return -1;
}

