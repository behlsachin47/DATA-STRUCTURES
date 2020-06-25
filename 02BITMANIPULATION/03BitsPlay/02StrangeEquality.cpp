/*Strange Equality
 * Problem Description
 * Given an integer A.
 * Two numbers X and Y are defined as follows:
 * X is the greatest number smaller than A such that XOR sum of X and A is the
 * same as the sum of X and A.
 * Y is the smallest number greater than A such that XOR sum of Y and A is the
 * same as the sum of Y and A.
 * Find and return the XOR of X and Y. NOTE 1: XOR of X and Y is defined as
 * X ^ Y where '^' is the BITWISE XOR operator. NOTE 2: Your code will be run
 * against a maximum of 100000 Test Cases.   
 *
 *
 * Problem Constraints
 * 1 <= A <= 109
 *
 *
 * Input Format
 * First and only argument is an integer A.
 *
 *
 * Output Format
 * Return an integer denoting the XOR of X and Y.
 *
 *
 *
 * */

int Solution::solve(int A) {
    if (A == 0)
        return 1;
    int ans = 0;
    int lastSetBit = -1;
    int mask = 1;
    for (int i = 0; i < 32; i++) {
        if ((A & mask) != 0) {
            lastSetBit = i;
        }
        mask = mask << 1;
    }
    ans = ~A;
    mask = pow(2, lastSetBit)-1;
    ans = ans & mask;
    mask = 1 << (lastSetBit+1);
    ans = ans | mask;
    
    return ans;
    
    
    
    
}

