typedef std::pair<char, int> ciPair;
class Solution {
public:
    string removeDuplicates(string input, int k) {
        std::stack<int> counts;
        int st = 0;        
        for (int i = 0; i < input.size(); i++) {
            if (counts.empty() == false && input[st-1] == input[i])  {
                //before inserting; check if this can even be inserted
                if (counts.top() == k-1) {
                  //remove last k-1
                  int j = 0;
                  while (j < k-1) {
                    counts.pop();
                    j++;
                  }
                  st -= k-1;
                } else {
                    input[st++] = input[i];
                    counts.push(counts.top()+1);
                }    
            } else {
                input[st++] = input[i];
                counts.push(1);
            }
        }
        
        return input.substr(0, st); 
    
    }
};
