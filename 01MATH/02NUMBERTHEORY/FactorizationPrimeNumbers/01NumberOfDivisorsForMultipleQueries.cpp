void solve2(const std::vector<int>& sieve, int element, std::unordered_map<int,
int>& factorFreqMap) {
    if (element == 1) {
        return;
    } else {
        int sf = sieve[element];
        if (factorFreqMap.count(sf))
            factorFreqMap[sf]++;
        else 
            factorFreqMap.insert(std::make_pair(sf, 1));
        
        solve2(sieve, element/sf, factorFreqMap);
    }
    
    
}
vector<int> Solution::solve(vector<int> &A) {
    int maxElement = A[0];
    for (int i = 0; i < A.size(); i++)
        maxElement = std::max(maxElement, A[i]);
        
        
    std::vector<int> sieve (maxElement+1, 0);
    for (int i = 0; i <=maxElement; i++) {
        sieve[i] = i;
    }
    
    for (int i = 2; i <= sqrt(maxElement); i++) {
        if (sieve[i] == i) {
            for (int j = i*i; j <= maxElement; j+= i) {
                if (sieve[j] == j) {
                    sieve[j] = i;
                }
            }
        }
    }
    
    std::vector<int> output(A.size(), 0);
    for (int i = 0; i < A.size(); i++) {
        std::unordered_map<int, int> factorFreqMap;
        solve2(sieve, A[i], factorFreqMap);
        int answer = 1;
        for (auto iter = factorFreqMap.begin(); iter != factorFreqMap.end();
iter++) {
            answer *= (iter->second+1);
        }
        output[i] = answer;
    }
    
    return output;
}   

