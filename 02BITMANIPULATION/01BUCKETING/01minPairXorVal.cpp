/*
 * Observation:
 *  we can observe that to find the minimum xor value; we need to reduce the
 *  chancesof set bits in the msb side.
 *
 *  Lets have 0-7 numbers; binary representation
 *  000
 *  001
 *  010
 *  011
 *  100
 *  101
 *  110
 *  111
 *
 *  By intution; we can observe one thing here is that the mimium xor is
 *  between the conssecutive numbers. Although that does not mean the
 *  conssecutive xor will always be less than the not connsecutive ones. 
 *
 *  eg. lets take three numbers: 3, 4, 5
 *  3^4 = 7
 *  4^5 = 1
 *  3^5 = 5
 *
 *  But minium lies between connsecutive numbers; what we should also observe
 *  that 3^4 > 3^5 > 4^5
 * 
 *  MATHEMATICAL PROOF: 
 *    TO PROVE: that the xor shall be minimum between two conssecutive numbers.
 *    Lets take numbers a; b and c
 *
 *    Binary representation
 *    a: (31-d bits) (d_bit) (d-1 bits)
 *    c: (31-d bits) (d_bit) (d-1 bits) 
 *
 *    So here the first 31-d bits are same and d_bit is different in a and c;
 *    assuming a< c; we can say that d_bit is 0 in a and 1 in c.
 *
 *    No assuming there exists a number b between a and c. b's d_bit can be
 *    both 1 and 0. First 31-d bits are same in all a; b; and c.
 *
 *    binary rep: 
 *    a: (same) 0 (d-1 bits)
 *
 *    b: (same) 0 (d-1 bits)
 *    OR
 *    b: (same) 1 (d-1 bits)
 *
 *    c: (same) 1 (d-1 bits)
 *
 *
 *
 *    case1: b's dth bit is 0
 *    xor value of dth bit:
 *      a^b : 0
 *      b^c : 1
 *      a^c : 1
 *
 *      so minimum here is a^b
 *
 *    case2: b's dth bit is 1
 *    xor value of dth bit:
 *      a^b : 1
 *      b^c : 0
 *      a^c : 1
 *
 *      so minimum here is b^c 
 *
 * */


int Solution::findMinXor(vector<int> &A) {
    std::sort(A.begin(), A.end());
    int ans = A[0] ^A[1];
    for (int j = 2; j < A.size(); j++)
    {
        int smallAns = A[j-1]^A[j];
        if(ans > smallAns)
            ans = smallAns;
    }
    return ans;
}

