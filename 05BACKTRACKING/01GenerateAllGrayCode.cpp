#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
typedef long long ll;
int count = 0;
ll to_decimal(std::string str) {
    ll output = 0;
    ll power = 1;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '1')
            output += power;
        power = power*2;
    }
    return output;
}
void solve(std::string& str, std::unordered_set<std::string>& map1,
std::vector<int>& output  ) {
    if (map1.count(str))
        return;
    std::cout << count++ << " " << str << std::endl;
    output.push_back(to_decimal(str));
    map1.insert(str);
    
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0')
            str[i] = '1';
        else if (str[i] == '1') {
            str[i] = '0';
        }
        if (!map1.count(str))
            solve(str, map1, output);
        
        if (str[i] == '0')
            str[i] = '1';
        else if (str[i] == '1') {
            str[i] = '0';
        } 
    }
}
vector<int> grayCode(int A) {
    std::string str(A, '0');
    std::vector<int> output;
    std::unordered_set<std::string> map1;
    
    solve(str, map1, output);
    
    return output;
    
}

int main() {
  int num;
  std::vector<int> ans = grayCode (16);
  for (int i = 0; i < ans.size(); i++) 
    std::cout << ans[i] << std::endl;
}
