int findPivot(const std::vector<int>& vec) {
    int low = 0;
    int high = vec.size()-1;
    int lastElem = vec[high];
    int ans = high;
    
    while (low <= high) {
        int mid = low + (high-low)/2;
        
        if (vec[mid] <= lastElem) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return ans;
}
int Solution::search(const vector<int> &A, int B) {
    int pivot = findPivot(A);
    int low = 0;
    int high = A.size()-1;
    
    if (B > A[high]) {
        high = pivot-1;
    } else {
        low = pivot;
    }
    
    int ans = -1;
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
    return ans;
}

