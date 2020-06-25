typedef long long ll;
ll MOD= 1000000007;
int Solution::hammingDistance(const vector<int> &A) {
    std::vector<ll> onesArr(32, 0);
    int n = A.size();
    for (int i = 0; i < n; i++) {
        int temp = A[i];
        int bit = 0;
        while (temp != 0) {
            if (temp % 2 == 1)
                onesArr[bit]++;
            temp = temp/2;
            bit++;
        }
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int temp = A[i];
        int bit = 0;
        while (bit < 32) {
            int numOnes = onesArr[bit];
            int numZeros = n- numOnes;
            if (temp % 2 == 1) {
                ans += numZeros;
                ans %= MOD;
            } else {
                ans += numOnes;
                ans %= MOD;
            }
            temp = temp/2;
            bit++;
        }

    }
    return ans;
}

