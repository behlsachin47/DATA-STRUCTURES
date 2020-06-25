
int Solution::solve(vector<int> &A) {
    int n = A.size();
    int low = 0;
    int high = A.size()-1;
    
    while (low <= high) {
        int mid = low + (high-low)/2;
        bool isSingle = true;
        if (mid - 1 >= 0 && A[mid-1] == A[mid]) {
            isSingle = false;
            mid = mid-1;
        } else if (mid+1 < n && A[mid+1] == A[mid]) {
            isSingle = false;
        }
        
        if (isSingle) {
            return A[mid];
        }
        if (mid % 2 == 0) {
            low = mid+2;
        } else {
            high = mid-1;
        }
    }
    return -1;
}

