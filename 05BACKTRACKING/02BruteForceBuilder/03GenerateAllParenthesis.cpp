class Solution {
public:
    
    void generateAll(int openBrace, int closedBrace, std::string& path,
std::vector<std::string>& output, int n) {

        if (path.size() == 2*n) {
            output.push_back(path);
            return;
        }
        
        if (openBrace > 0) {
            path.push_back('(');
            generateAll(openBrace-1, closedBrace, path, output, n);
            path.pop_back();    
        }
        
        if (openBrace < closedBrace) {
            path.push_back(')');
            generateAll(openBrace, closedBrace-1, path, output, n);
            path.pop_back();    
        }
        
        
    }
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> output;
        std::string path;
        
        int alreadyOpened = 0;
        int closedLeft = n;
        
        generateAll(n, n, path, output, n);
        return output;
    }
};
