class Solution {
public:
    string removeDuplicates(string S) {
        //using two pointers
        int st = 0;
        for (int i = 0; i < S.size(); i++) {
            if (st != 0 && S[i] == S[st-1]) {
                st--;
            } else {
                S[st++] = S[i];
            }
        }
        
        return S.substr(0, st);
    }
};