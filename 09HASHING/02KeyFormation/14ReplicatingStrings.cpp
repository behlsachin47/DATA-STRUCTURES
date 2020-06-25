int Solution::solve(int A, string B) {
    std::unordered_map<char, int> mapChar;
    for (int i = 0; i < B.size(); i++) {
        if (mapChar.count(B[i]))
            mapChar[B[i]]++;
        else
            mapChar.insert({B[i], 1});
    }
    
    for (auto iter = mapChar.begin(); iter != mapChar.end(); iter++) {
        if (iter->second % A != 0)
            return -1;
    }
    return 1;
}
