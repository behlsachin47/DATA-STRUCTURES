vector<int> Solution::dNums(vector<int> &A, int B) {
    std::vector<int> res;
    if (A.size() < B) {
        return res;
    }
    std::unordered_map<int, int> valueFreqMap;
    
    for (int i = 0; i < B-1; i++) {
        if (valueFreqMap.count(A[i])) {
            valueFreqMap[A[i]]++;
        } else {
            valueFreqMap.insert({A[i], 1});
        }
    }    
    
    for (int i = B-1; i < A.size(); i++) {
        if (i != B-1) {
            //remove the i-B element
            valueFreqMap[A[i-B]]--;
            if (valueFreqMap[A[i-B]] == 0) {
                valueFreqMap.erase(A[i-B]);
            }
        }
        
        //push the ith element
        if (valueFreqMap.count(A[i])) {
            valueFreqMap[A[i]]++;
        } else {
            valueFreqMap.insert({A[i], 1});
        }
        
        res.push_back(valueFreqMap.size());
    }
    
    return res;
    
}
