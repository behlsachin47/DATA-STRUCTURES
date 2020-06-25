vector<int> Solution::maxone(vector<int> &A, int B) {
    int ptr1 = 0;
    int ptr2 = 0;
    int ansLeng = 0;
    int countZeros = 0;
    int startAns = -1;
    int endAns = -1;
    while (ptr2 < A.size()) {
       if (A[ptr2] == 0) {
            if (countZeros < B) {
                countZeros++;
            } else {
                while (A[ptr1] != 0) {
                    ptr1++;
                }
                ptr1++;
                ptr2++;
                continue;
            }
        } 
        if (ptr2 - ptr1 + 1 > ansLeng) {
            ansLeng = ptr2 - ptr1 + 1;
            startAns = ptr1;
            endAns = ptr2;
        }
        ptr2++;

        
    }
    std::vector<int> ans;
    for (int i = startAns; i <= endAns && ansLeng > 0; i++) {
        ans.push_back(i);
    }
    
    return ans;
}

