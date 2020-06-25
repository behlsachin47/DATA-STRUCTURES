bool checkContainment(std::unordered_map<char, int>& temp, std::unordered_map<char, int>& mapCharToFreq) {
    if (mapCharToFreq.size() != temp.size())
        return 0;
    for (auto iter = mapCharToFreq.begin(); iter != mapCharToFreq.end(); iter++) {
        char ch = iter->first;
        int freq = iter->second;
        
        if (temp.count(ch) == 0 || temp[ch] < freq)
            return 0;
    }
    return 1;
}

class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> mapCharToFreq;
        for (int i = 0; i < t.size(); i++) {
            if (mapCharToFreq.count(t[i])) {
                mapCharToFreq[t[i]]++;
            } else {
                mapCharToFreq.insert({t[i], 1});
            }
        }
        int ansStart = -1;
        int ansEnd = 0;
        std::unordered_map<char, int> temp;        
        int start = 0;
        bool isContained = false;
        char lastDeletedChar;
        
        for (int i = 0; i < s.size(); i++) {
            //std::cout << start << " " << i << std::endl;
            if (mapCharToFreq.count(s[i])) {
                if (temp.count(s[i])) 
                    temp[s[i]]++;
                else
                    temp.insert({s[i], 1});
            } else {
                continue; // TODO
            }
            
            if (!isContained) {
                if (checkContainment(temp, mapCharToFreq)) {
                    isContained = true;
                    //trim the start point
                    for (; start < i; ) {
                        if (mapCharToFreq.count(s[start]) == 0 || temp[s[start]] > mapCharToFreq[s[start]]) {
                            
                            if (temp.count(s[start]))
                            temp[s[start]]--;
                            
                            start++;
                        } else {
                            break;   
                        }
                    }
                    ansStart = start;
                    ansEnd = i;
                    lastDeletedChar = s[start];
                    temp[s[start]]--;
                    start++;
                }
            } else {
                if (lastDeletedChar == s[i]) {
                    //trim the start
                    for (;start < i; ) {
                        if (mapCharToFreq.count(s[start]) == 0 || temp[s[start]] > mapCharToFreq[s[start]]) {
                            if (temp.count(s[start]))
                                temp[s[start]]--;
                            start++;
                        } else {
                            //start--;
                            break;   
                        }

                    }

                    if (ansEnd-ansStart > i- start ) {
                        ansStart = start;
                        ansEnd = i;
                    }
                    temp[s[start]]--;
                    lastDeletedChar = s[start];
                    start++;
                }
            }
            
            
        }
        if (ansStart == -1)
            return std::string("");
        return s.substr(ansStart, ansEnd-ansStart+1);
    }
};