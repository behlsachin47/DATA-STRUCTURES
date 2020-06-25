vector<int> Solution::primesum(int A) {
    std::vector<bool> sieve(A+1, true);
    sieve[0] = 0;
    sieve[1] = 0;
    
    std::vector<int> res;
    for (int i = 2; i*i <= A; i++) {
        if (sieve[i] == 1) {
            for (int j = i*i; j <= A; j+=i)
                sieve[j] = false;
        }
    }
    
    for (int i = 2; i <= A; i++) {
        if (sieve[i] == 1) {
            if (sieve[A-i]) {
                res.push_back(i);
                res.push_back(A-i);
                break;
            }
        }
    }
    
    return res;
    
}

