class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1)
            return s.size();
        
        std::unordered_set<int> set1;
        int ans = 1;
        int currSt = 0;
        //int currEnd = 0;
        for (int i = 0; i < s.size(); i++) {
            if (set1.count(s[i]) == 0) {
                set1.insert(s[i]);
                if (i-currSt+1 > ans) {
                    ans = i-currSt+1;
                } 
            } else {
                //now increase our currSt
                for (; currSt < i; currSt++) {
                    if (s[i] == s[currSt]) {
                        currSt ++;
                        break;
                    } else {
                        set1.erase(s[currSt]);
                    }
                }
            }
        }
        return ans;
    }
};