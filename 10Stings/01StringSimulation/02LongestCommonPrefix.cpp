string Solution::longestCommonPrefix(vector<string> &A) {
    int minLength = INT_MAX;
    int commonIndex = 0;
    for (int i = 0; i < A.size(); i++) {
        minLength = std::min(minLength, (int)A[i].size());
    }
    
    if (minLength == 0) {
        return "";
    }
    
    char charToCompare;
    bool flag = 1;
    for (int i = 0; i < minLength; i++) {
        for (int j = 0; j < A.size(); j++) {
            if (j == 0) {
                charToCompare = A[j][i];
            } else {
                if (charToCompare != A[j][i])
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            commonIndex++;
        } else {
            break;
        }
    }
    
    return A[0].substr(0, commonIndex);
}
