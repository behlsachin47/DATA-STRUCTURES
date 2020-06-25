#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
	//code
	int t, n, m;
	std::cin >> t;
	while (t--) {
	    std::cin >> n >> m;
	    std::vector<int> vec1;
	    std::vector<int> vec2;
	    std::unordered_set<int> set1;
	    int sum1, sum2;
	    sum1 = sum2 = 0;
	    for (int i = 0; i < n; i++) {
	        int temp;
	        std::cin >> temp;
	        
            vec1.push_back(temp);	        
	        sum1 += temp;
	    }
	    
	    for (int i = 0; i < m; i++) {
	        int temp;
	        std::cin >> temp;
	        sum2 += temp;
	        
	        vec2.push_back(temp);
	        set1.insert(vec2[i]);
	    }
	    
	    int diff = sum1-sum2;
	    	    //std::cout << diff << std::endl;

	    if (diff % 2 != 0)
	    {
	        std::cout << -1 << std::endl;
	        continue;
	    }
	    bool flag = 0;
	    for (int i = 0; i < n; i++) {
	        int num1 = vec1[i];
	        int numToFind = num1-(diff/2);
	        if (set1.count(numToFind)) {
	            std::cout << 1 << std::endl;
	            flag = 1;
	            break;
	        }
	    }
	    if (!flag)
	    std::cout << -1 << std::endl;
	    
	}
	return 0;
}