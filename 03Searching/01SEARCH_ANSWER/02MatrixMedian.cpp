int findLesserEqual(int x, const std::vector<int>& vec) {
    int low = 0;
    int high = vec.size()-1;
    int ans = -1;
    
    while (low <= high) {
        int mid = low + (high-low)/2;
        if (vec[mid] <= x) {
            ans = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return ans+1;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int low = INT_MAX;
    int high = INT_MIN;
    int r = A.size();
    int c = A[0].size();
    int ans = low;
    for (int i =0; i < r; i++)
        low = std::min(low, A[i][0]);
    for (int i = 0; i < r; i++) 
        high = std::max(high, A[i][c-1]);
        
    
    while (low <= high) {
        int mid = low + (high-low)/2;
        int count = 0;
        for (int i = 0; i < r; i++) 
            count += findLesserEqual(mid, A[i]);
            
        if (count >= (r*c+1)/2) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return ans;
}

