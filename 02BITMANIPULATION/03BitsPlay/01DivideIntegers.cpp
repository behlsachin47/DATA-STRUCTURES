typedef long long ll;
int Solution::divide(int A_, int B_) {
    ll A = A_;
    ll B = B_;
    if (A == INT_MIN && B == -1) {
        return INT_MAX;
    } else if (A == INT_MIN && B == 1) {
        return INT_MIN;
    }
    
    bool isNeg = 0;
    if (A < 0) {
        A = -A;
        isNeg = !isNeg;
    }
    if (B < 0) {
        B = -B;
        isNeg = !isNeg;

    }

    ll q = 0;
    while (A >= B) {
        ll powerOfTwo = 0;
        ll val = B;
        while (val <= A) {
            val += val;
            powerOfTwo += 1;
        }
        
        
        powerOfTwo --;
        A -= pow(2, powerOfTwo)*B;
        q += pow(2, powerOfTwo);
        
        
    }
    if (isNeg)
        q= -1*q;
    return q;
    
}

