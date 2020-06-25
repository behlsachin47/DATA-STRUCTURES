/*Another Count Rectangles
 * Problem Description
 * Given a sorted array of distinct integers A and an integer B, find and
 * return how many rectangles with distinct configurations can be created using
 * elements of this array as length and breadth whose area is lesser than B.
 * (Note that a rectangle of 2 x 3 is different from 3 x 2 if we take
 * configuration into view)  
 *
 *
 * Problem Constraints
 * 1 <= |A| <= 100000 1 <= A[i] <= 10^9 1 <= B <= 10^9  
 *
 *
 * Input Format
 * The first argument given is the integer array A. The second argument given
 * is integer B.  
 *
 *
 * Output Format
 * Return the number of rectangles with distinct configurations with area less
 * than B modulo (10^9 + 7).
 *
 *
 * Example Input
 * Input 1:
 * A = [1, 2]
 * B = 5
 *   Input 2:        
 *   A = [1, 2]
 *   B = 1
 *        
 *
 *
 * */





typedef long long ll;
ll MOD = 1000000007;
int Solution::solve(vector<int> &A, int B) {
    ll i = 0;
    ll j = A.size()-1;
    ll ans = 0;
    B = B%MOD;
    while (i <= j) {
        ll area = (ll)A[i] * (ll)A[j];
        if (area < B ) {
            ll smallAns = ((j-i)*2 + 1);
            smallAns %= MOD;
            ans += smallAns;
            ans %= MOD;
            i++;
        } else {
            j--;
        }
    }
    return ans;
}

