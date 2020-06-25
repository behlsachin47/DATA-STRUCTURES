int longestPalindromeUtil(const std::string& str, int mid, int& st, int& end) {
    //takind mid as mid; i.e. we have odd size palindrome
    int ptr1 = mid-1;
    int ptr2 = mid+1;
    int ans1 = 1;
    int ans = 1;
    while (ptr1 >= 0 && ptr2 < str.size()) {
        if (str[ptr1] == str[ptr2]) {
            ptr1--;
            ptr2++;
        } else {
            break;
        }
    } 
    st = ptr1+1;
    end = ptr2-1;
    ans1 = end - st + 1;    
    //std::cout << "DEBUG: " << mid << ": " << st << "," << end << std::endl; 
    ans = ans1;
    
    
    
    
    int ans2 = 0;
    ptr1 = mid;
    ptr2 = mid+1;
    while (ptr1 >= 0 && ptr2 < str.size()) {
        if (str[ptr1] == str[ptr2]) {
            ptr1--;
            ptr2++;
        } else {
            break;
        }
    }
    ptr1++;
    ptr2--;
    
    if (ptr1 != ptr2) {
        ans2 = ptr2 - ptr1 +1;
    }
    
    if (ans2 > ans1) {
        st = ptr1;
        end = ptr2;
        ans = ans2;
    }
    
    //std::cout << "DEBUG2: " << mid << ": " << ptr1 << "," << ptr2 << std::endl; 
    return ans;
}

string Solution::longestPalindrome(string A) {
    //lets find the longest palinderome as A[i] as the middle elemet
    int ans = 0;
    int ansSt = -1;
    int ansEnd = -1;
    for (int mid = 0; mid < A.size(); mid++) {
        int st = -1;
        int end = -1;
        
        int smallAns = longestPalindromeUtil(A, mid, st, end);
        if (ans < smallAns) {
            ansSt = st;
            ansEnd = end;
            ans = smallAns;
        } else if (ans == smallAns && ansSt > st) {
            ansSt = st;
            ansEnd = end;
        } 
    }
    if (ansSt == -1)
        return "";
    return A.substr(ansSt, ansEnd- ansSt+1);
}
