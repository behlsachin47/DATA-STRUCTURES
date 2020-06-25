typedef long long ll;

/* WHY APPLY BINARY SEARCH HERE ??
 * FIRST ANSWER CAN BE IN THE 1 TO n. check1
 * we can iteratively try answers and get to it.
 * 
 * MONOTONOUS: if f(x) = 1; i.e is possible that x is the answer; we can say
 * that values less than x cannot be the answer and hence ignore them.
 *
 *
 * */

int Solution::sqrt(int A) {
    if (A == 0)
        return 0;
    
    ll ansLow = 1;
    ll ansHigh = A;
    ll ans = 1;
    while (ansLow <= ansHigh) {
        ll mid = ansLow + (ansHigh - ansLow)/2;
        
        if (mid * mid <= A) {
            ans = mid;
            ansLow = mid+1;
        } else {
            ansHigh = mid-1;
        }
    }
    
    return ans;
 }

