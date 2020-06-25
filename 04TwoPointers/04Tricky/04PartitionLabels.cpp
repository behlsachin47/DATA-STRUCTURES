class Solution {
public:
    vector<int> partitionLabels(string S) {
        std::vector<int> mapAlphaIndex(26, -1);
        std::vector<int> answer;
        int n = S.size();
        
        for (int i = n-1; i >= 0; i--) {
            int charIndex = S[i]- 'a';
            if (mapAlphaIndex[charIndex] == -1)
                mapAlphaIndex[charIndex] = i;
        }
        
        
        int ptr1 = 0;
        int currBoundary = ptr1;
        for (int ptr2 = 0; ptr2 < n; ) {
            //currwindow
            //ptr1 to ptr2
            while (1) {
                currBoundary = std::max(currBoundary, mapAlphaIndex[S[ptr2]- 'a']);
                
                
                if (currBoundary == ptr2)
                    break;
                ptr2++;
            }
            
            answer.push_back(ptr2-ptr1+1);
            ptr1 = ptr2+1;
            currBoundary = ptr1;
            ptr2++;
            
        }
        
        return answer;
    }
};