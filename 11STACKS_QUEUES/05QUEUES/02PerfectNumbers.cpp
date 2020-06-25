int totalDigitsWith(int n) {
    return 2*(pow(2, n)-1);
}
string Solution::solve(int A) {
    //lets first find out how many digits we need for this
    //2 => 1 digit
    //4 -> 
    
    int nd = log2((A+1)/2) + 1;
    int offset = 0;
    
    if (nd != 1)
        offset = A- totalDigitsWith(nd-1);
    else 
        offset = A;
    //std::cout << nd << " " << offset << std::endl;
    std::string curr = std::string(nd, '1');
    for (int i = 1; i < offset; i++) {
        bool carry = 1;
        for (int j = nd-1; j >= 0; j--) {
            if (carry) {
                if (curr[j] == '1') {
                    curr[j] = '2';
                    carry = 0;
                } else {
                    curr[j] = '1';
                }
            } else {
                break;
            }
        }
    }
    std::string reverseCurr = curr;
    std::reverse(reverseCurr.begin(), reverseCurr.end());
    
    return curr + reverseCurr ;
    
    
    
    
}
