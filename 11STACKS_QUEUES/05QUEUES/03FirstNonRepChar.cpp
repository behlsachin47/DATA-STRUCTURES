string Solution::solve(string A) {
    std::unordered_map<char, int> mapCharFreq;
    std::queue<char> queue1;
    std::string result;
    
    for (int i = 0; i < A.size(); i++) {
        if(mapCharFreq.count(A[i]))
            mapCharFreq[A[i]]++;
        else {
            queue1.push(A[i]);
            mapCharFreq.insert({A[i], 1});
        }
        bool flag = 0;
        while (queue1.size()) {
            char temp = queue1.front();
            if (mapCharFreq[temp] == 1) {
                result.push_back(temp);
                flag = 1;
                break;
            } else {
                queue1.pop();
            }
        }
        if (!flag)
            result.push_back('#');
    }
    
    return result;
}
