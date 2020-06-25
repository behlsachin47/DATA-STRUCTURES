
typedef long long ll;
ll MOD = 1000000007;
int Solution::cntBits(vector<int> &A) {
    ll mask = 1;
    ll ans = 0;
    for (int i = 0; i < 32; i++) {
        ll countOne = 0;
        ll countZero = 0;
        for (int j = 0; j < A.size(); j++) {
            if ((A[j] & mask) != 0)
                countOne++;
            else
                countZero++;
        }
        ans += (countOne*countZero)%MOD;
        ans %= MOD;
        mask = mask << 1;
    }
    ans = ans*2;
    ans %= MOD;
    return ans;
}

