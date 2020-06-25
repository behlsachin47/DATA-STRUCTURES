int Solution::searchInsert(vector<int> &A, int B) {
    int low = 0;
    int high = A.size()-1;
    
    int ans = high+1;
    while (low <= high) {
        int mid = low + (high-low)/2;
        if (A[mid] == B) {
            return mid;
        } else if (A[mid] > B) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
            
        }
    }
    return ans;
}

