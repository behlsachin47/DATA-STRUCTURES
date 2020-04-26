int gcd(int A, int B) {
    if (B == 0)
        return A;
    else
        return gcd(B, A%B);
}

int Solution::solve(vector<int> &A) {
    if (A.size() <= 1)
        return -1;
    int ans = 1;
    int n = A.size();
    std::vector<int> gcdLeft(n, 1);
    std::vector<int> gcdRight(n, 1);
    
    gcdLeft[0] = A[0];
    for (int i = 1; i < n; i++) {
        gcdLeft[i] = gcd(gcdLeft[i-1], A[i]);
    }
    
    gcdRight[n-1] = A[n-1];
    for (int i = n-2; i >= 0; i--) {
        gcdRight[i] = gcd(gcdRight[i+1], A[i]);
    }
    
    for (int i = 0; i < n; i++) {
       if (i == 0) {
           ans = std::max(ans, gcdRight[i+1]);
       }  else if (i == n-1) {
           ans = std::max(ans, gcdLeft[i-1]);
       } else {
           ans = std::max(ans, gcd(gcdLeft[i-1], gcdRight[i+1]));
       }
    }
    
    return ans;
    
    
}

