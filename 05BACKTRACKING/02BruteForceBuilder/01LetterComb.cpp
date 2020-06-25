class Solution {
public:
    std::vector<string> mapDigitKey = {"0", "1", "abc", "def", "ghi", "jkl",
"mno", "pqrs", "tuv", "wxyz"};
    
    void generateAllComb(std::string& digits, int index, std::string& iter,
    std::vector<std::string> output ) {
      if (index == digits.size()) {
        output.push_back(iter);
        return;
      }

      int digit = digits[index] - '0';
      std::string keys = mapDigitKey[digit];

      for(int i = 0; i < keys.size(); i++) {
        iter[index] = keys[i];
        generateAllComb(digits, index+1, iter, output);
      }
    
    }
    vector<string> letterCombinations(string digits) {
      std::string iter (digits.size(), 'a');
      std::vector<std::string> output;

      generateAllComb(digits, 0, iter, output);
      return output;
    }
};


