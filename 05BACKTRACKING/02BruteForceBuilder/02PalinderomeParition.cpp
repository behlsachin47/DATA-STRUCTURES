class Solution {
public:
    
    bool isPalindrome(std::string str, int ptr1, int ptr2) {
        while(ptr1 < ptr2) {
            if (str[ptr1] != str[ptr2])
                return false;
            ptr1++;
            ptr2--;
        }
        
        return 1;
    }
    vector<vector<string>> partition(string s) {
        std::vector<std::string> path;
        std::vector<std::vector<string>> ans;
        dfs(s, 0, path, ans);
        return ans;
    }
    
    void dfs(string& s, int index, std::vector<std::string>& path,
std::vector<std::vector<string>>& ans) {
        if (s.size() == index) {
            ans.push_back(path);
            return;
        }
        
        for (int i = index; i < s.size(); i++) {
            
            if (isPalindrome(s, index, i)) {
                int len = i - index + 1;
                std::string temp = s.substr(index, len);
                path.push_back(temp);
                dfs(s, i+1, path, ans);
                path.pop_back();
            }
        }
        
        
    }
};


//partition possible 2^n-1
