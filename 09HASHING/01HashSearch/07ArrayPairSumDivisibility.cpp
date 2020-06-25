#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	std::cin >> t;
	while (t--) {
	    int n, k;
	    int ans = 1;
	    std::cin >> n;
	    std::vector<int> vec;
	    std::unordered_map<int, int> valueFreqMap;

	    for (int i = 0; i < n; i++) {
	        int temp;
	        std::cin >> temp;
	        vec.push_back(temp);
	    }
	    
	    std::cin >> k;
	    
	    
	    for (int i = 0; i < n; i++) {
	        int remainder = vec[i] % k;
	        if (valueFreqMap.count(remainder)) {
	            valueFreqMap[remainder]++;
	        } else {
	            valueFreqMap.insert({remainder, 1});
	        }
	    }
	    /*for (auto iter = valueFreqMap.begin(); iter != valueFreqMap.end(); iter++) {
	        std::cout << iter->first << " " << iter->second << std::endl;
	        
	    }*/
	    for (auto iter = valueFreqMap.begin(); iter != valueFreqMap.end(); iter++) {
	        int remainder = iter->first;
	        int freq = iter->second;
	        
	        if (remainder == 0 || remainder == k-remainder) {
	            if (freq % 2 != 0) {
	                ans = 0;
	                break;
	            } 
	        } else if (remainder > k-remainder) {
	            continue;
	        } else {
	            int freq2 = valueFreqMap[k-remainder];
	            if (freq != freq2) {
	                ans = 0;
	                break;
	            }
	        }
	    }
	    if (ans) 
	    std::cout << "True" << std::endl;
	    else
	    std::cout << "False\n"; 
	}
	return 0;
}