string Solution::countAndSay(int A) {
    std::string ans = "1";
    int count = 1;
    
    while (count < A) {
        std::string prevAns = ans;
        ans = "";
        for (int i = 0; i < prevAns.size(); ) {
            int j = i;
            while (j < prevAns.size() && prevAns[i] == prevAns[j]) {
                j++;
            }
            char countChar = j - i + '0';
                        ans += countChar;

            ans +=  prevAns[i];
            
            i = j;
        }
        //std::cout << ans << std::endl;
        count++;
        
    }
    return ans;
}
