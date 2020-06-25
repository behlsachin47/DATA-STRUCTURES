#include <iostream>
#include <vector>
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a%b);
}
int Solution::solve(std::vector<int> &A) {
    int n = A.size();
    int prefixGCD = 0;
    std::vector<int> suffixGCD(n, 0);
    int answer = 1;
    for (int i = n-2; i >= 0; i--) {
        suffixGCD[i] = gcd(suffixGCD[i+1], A[i+1]); 
    }
    
    for (int i = 0; i < n; i++) {
        answer = std::max(answer, gcd(prefixGCD, suffixGCD[i]));
        prefixGCD = gcd(prefixGCD, A[i]);
    }
    
    return answer;
}

