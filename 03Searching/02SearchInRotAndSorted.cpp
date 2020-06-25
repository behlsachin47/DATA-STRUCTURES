int findPivot(const std::vector<int>& A) {
    
    int n = A.size();
    int lastElem = A[n-1];
    int ans = -1;
    int low = 0;
    int high = n-1;
    
    while (low <= high) {
        int mid = low + (high-low)/2;
        
        if (A[mid] <= lastElem) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    
    return ans;
}

int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    int pivotIndex = findPivot(A);
    int low = 0;
    int high = n-1;
    if (A[n-1] >= B) {
        low = pivotIndex;
        high = n-1;
    } else {
        low = 0;
        high = pivotIndex-1;
    }
    while (low <= high) {
        int mid = low + (high-low)/2;
        if (A[mid] == B) {
            return mid;
        } else if (A[mid] > B) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    
    return -1;
    
}

