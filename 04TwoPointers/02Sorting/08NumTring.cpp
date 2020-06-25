typedef long long ll;
ll MOD = 1000000007;
int Solution::nTriang(vector<int> &A) {
    ll ans = 0;
    std::sort(A.begin(), A.end(), std::greater<int>());
    int n = A.size();
    for (int i = 0; i < n-2; i++) {
        int ptr1 = i+1;
        int ptr2 = n-1;
        
        while (ptr1 < ptr2) {
            if (A[ptr1] + A[ptr2] > A[i]) {
                ans += (ptr2-ptr1) % MOD;
                ans %= MOD;
                ptr1++;
            } else {
                ptr2--;
            }
        }
    } 
    return ans;
    
}

