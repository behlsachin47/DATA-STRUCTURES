int Solution::threeSumClosest(vector<int> &A, int B) {
    std::sort(A.begin(), A.end());
    int n = A.size();
    int ans = -1;
    int diff = INT_MAX;
    for (int i = 0; i < n-2; i++) {
        int ptr1 = i+1; 
        int ptr2 = n-1;
        
        
        while (ptr1 < ptr2) {
            int sum = A[i] + A[ptr1] + A[ptr2];
            if (abs(sum-B) < diff) {
                diff = abs(sum-B);
                ans = sum;
            }
            
            if (sum == B) {
                return sum;
            } else if (sum > B) {
                ptr2--;
            } else {
                ptr1++;
            }
        }
    }
    return ans;
}

