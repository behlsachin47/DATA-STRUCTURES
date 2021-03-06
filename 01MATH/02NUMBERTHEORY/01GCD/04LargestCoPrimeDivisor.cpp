/*
 *
 *
 *We know A is the greatest number dividing A. So if A and B are coprime, we
 can return the value of X to be A. Else, we can try to remove the common
 factors of A and B from A.
 You are given two positive numbers A and B. You need to find the maximum
 * valued integer X such that:
 *
 * X divides A i.e. A % X = 0
 * X and B are co-prime i.e. gcd(X, B) = 1
 * For example,
 *
 * A = 30
 * B = 12
 * We return
 * X = 5
 *
 *
 * */
int gcd(int A, int B) {
    if (B == 0)
        return A;
    else
        return gcd(B, A%B);
}
int Solution::cpFact(int A, int B) {
    int g = gcd(A, B);
    while (g != 1) {
        A = A/g;
        g = gcd(A, B);
    }
    return A;
}

