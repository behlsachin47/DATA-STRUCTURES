

int Solution::solve(int A) {
    int ans = 0;
    for (int i = 1; i <= sqrt(2*A); i++) {
        int temp = (i*(i-1))/2;
        if ((A-temp)%i == 0) {
            ans++;
        }
    }
    return ans;
}

