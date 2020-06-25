int Solution::braces(string A) {
    std::stack<int> openingBraceIndex;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == '(') {
            openingBraceIndex.push(i);
        } else if (A[i] == ')') {
            if (i -openingBraceIndex.top() == 2) {
                return 1;
            } else if (i+1 < A.size() && A[i+1] == ')') {
                //check for redundancy
                int ind1 = openingBraceIndex.top();
                openingBraceIndex.pop();
                
                int ind2 = openingBraceIndex.top();
                
                if (ind1 - ind2 == 1) {
                    return 1;
                } 
            } else {
                openingBraceIndex.pop();
            }
        }
    }
    return 0;
}
