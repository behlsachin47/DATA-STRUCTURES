typedef long long ll;
int Solution::pow(int x, int n, int d) {
    if (x == 0)
        return 0;
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        if (x < 0) {
            return x+d;
        } 
        return x%d;
    }
    
    ll ans = pow(x, n/2, d);
    ans = (ans*ans)%d;
    
    if (n%2 != 0) {
        ans *= x;
        ans %= d;
    }
    
    if (ans < 0) {
        ans += d;
    }
    return ans;
    
}
