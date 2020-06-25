vector<int> Solution::twoSum(const vector<int> &A, int B) {
    std::vector<int> result;
    std::unordered_map<int, int> numToIndexMap;
    for (int i = 0; i < A.size(); i++) {
        if (numToIndexMap.count(B-A[i])) {
            int index1 = numToIndexMap[B-A[i]];
            result.push_back(index1+1);
            result.push_back(i+1);
            break;
        }
        
        if (numToIndexMap.count(A[i]) == 0) {
            numToIndexMap.insert({A[i], i});
        }
    }
    return result;
}
