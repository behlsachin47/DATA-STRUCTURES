typedef long long ll;
bool debug = 0;
ll MOD = 1000000007;
int Solution::maxSpecialProduct(vector<int> &A) {
    std::stack<int> stack1;
        std::stack<int> stack2;

    std::vector<int> leftSpecialValue;
    std::vector<int> rightSpecialValue;

    leftSpecialValue.push_back(0);
    stack1.push(0);
    
    for (int i = 1; i < A.size(); i++) {
        while (stack1.empty() == false && A[stack1.top()] <= A[i]) {
            stack1.pop();
        }
        if (stack1.empty())
            leftSpecialValue.push_back(0);
        else 
            leftSpecialValue.push_back(stack1.top());
        
        stack1.push(i);
    }
    
    rightSpecialValue.push_back(0);
    stack2.push(A.size()-1);
    for (int i = A.size()-2; i >= 0; i--) {
        while (stack2.empty() == false && A[stack2.top()] <= A[i])
            stack2.pop();
        
        if (stack2.empty())
            rightSpecialValue.push_back(0);
        else
            rightSpecialValue.push_back(stack2.top());
        stack2.push(i);
    }
    std::reverse(rightSpecialValue.begin(), rightSpecialValue.end());
    
    if (debug) {
        for (int i = 0; i < A.size(); i++) {
            std::cout << leftSpecialValue[i] << " ";
        }
        std::cout << std::endl;
        
        for (int i = 0; i < A.size(); i++) {
            std::cout << rightSpecialValue[i] << " ";
        }
        std::cout << std::endl;
        
        
    }
    ll ans = 0;
    for (int i = 1; i <A.size()-1; i++) {
        ans = std::max(ans, (ll)leftSpecialValue[i]* (ll)rightSpecialValue[i]);
    }
    return ans%MOD;
    
}

