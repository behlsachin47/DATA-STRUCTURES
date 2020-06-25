int findLeftOccurence(const std::vector<int>& A, int B) {
    int low = 0;
    int high = A.size()-1;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high-low)/2;
        if (A[mid] == B) {
            ans = mid;
            high = mid-1;
        } else if (A[mid] < B) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return ans;
}


int findRightOccurence(const std::vector<int>& A, int B) {
    int low = 0;
    int high = A.size()-1;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high-low)/2;
        if (A[mid] == B) {
            ans = mid;
            low = mid+1;
        } else if (A[mid] < B) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return ans;
}
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int leftOccurence = findLeftOccurence(A, B);
    int rightOccurence = findRightOccurence(A, B);
    
    return std::vector<int> {leftOccurence, rightOccurence};
}

