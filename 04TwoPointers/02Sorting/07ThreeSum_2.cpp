typedef long long ll;
vector<vector<int> > Solution::threeSum(vector<int> &A) {
    int n = A.size();
    std::vector<std::vector<int> > output;
    std::sort(A.begin(), A.end());
    for (int i = 0; i < n-2; i++) {
        if (i > 0 && A[i] == A[i-1])
            continue;
        
            
        int ptr1 = i+1;
        int ptr2 = n-1;
        
        while (ptr1 < ptr2) {
            ll sum = (ll)A[i] + (ll)A[ptr1] + (ll)A[ptr2];
            if (sum == 0) {
                std::vector<int> smallAns {A[i], A[ptr1], A[ptr2]};
                output.push_back(smallAns);
                while (ptr1+1 <= ptr2  && A[ptr1+1] == A[ptr1]) {
                    ptr1++;
                }
                ptr1++;
                ptr2--;
            } else if (sum > 0) {
                ptr2--;
            } else {
                ptr1++;
            }
        }
    }
    
    
    
    return output;
    
    
}

