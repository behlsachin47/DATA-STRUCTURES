vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    std::unordered_map<string, std::vector<int>> mapStringToPositions;
    for (int i = 0; i < A.size(); i++) {
        std::string temp = A[i];
        std::sort(temp.begin(), temp.end());
        if (mapStringToPositions.count(temp)) {
            mapStringToPositions[temp].push_back(i+1);
        } else {
            mapStringToPositions.insert({temp, std::vector<int> {i+1}});
        }
    }
    
    std::vector<std::vector<int>> result;
    for (auto iter = mapStringToPositions.begin(); iter != mapStringToPositions.end(); iter++) {
        result.push_back(iter->second);
    }
    return result;
}
