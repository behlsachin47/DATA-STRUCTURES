typedef long long ll;
ll MOD = 1000000007;

void printVec(const std::vector<ll>& vec) {
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}
int Solution::solve(vector<int> &A) {
    bool debug = 0;
    std::vector<ll> leftMaxEqual;
    std::vector<ll> rightMax;
    std::vector<ll> leftLessEqual;
    std::vector<ll> rightLess;
    std::stack<int> stack1;
    ll n = A.size();
    
    for (int i = 0; i < A.size(); i++) {
        if (!stack1.empty() && A[stack1.top()] >= A[i]) {
            leftMaxEqual.push_back(stack1.top());
            stack1.push(i);
        } else if (!stack1.empty() && A[stack1.top()] < A[i]) {
            while (!stack1.empty() && A[stack1.top()] < A[i]) {
                stack1.pop();
            }
            
            i--;
        } else {
            stack1.push(i);
            leftMaxEqual.push_back(-1);
        }
    }
    
    stack1 = std::stack<int> ();
    
    for (int i = A.size()-1; i >= 0; i--) {
        if (!stack1.empty() && A[stack1.top()] > A[i]) {
            rightMax.push_back(stack1.top());
            stack1.push(i);
        } else if (!stack1.empty() && A[stack1.top()] <= A[i]) {
            while (!stack1.empty() && A[stack1.top()] <= A[i]) {
                stack1.pop();
            }
            
            i++;
        } else {
            stack1.push(i);
            rightMax.push_back(n);
        }
    }
    
    stack1 = std::stack<int>();
    
    for (int i = 0; i < A.size(); i++) {
        if (!stack1.empty() && A[stack1.top()] <= A[i]) {
            leftLessEqual.push_back(stack1.top());
            stack1.push(i);
        } else if (!stack1.empty() && A[stack1.top()] > A[i]) {
            while (!stack1.empty() && A[stack1.top()] > A[i]) {
                stack1.pop();
            }
            
            i--;
        } else {
            stack1.push(i);
            leftLessEqual.push_back(-1);
        }
    }
    
    
    stack1 = std::stack<int> ();
    
    for (int i = A.size()-1; i >= 0; i--) {
        if (!stack1.empty() && A[stack1.top()] < A[i]) {
            rightLess.push_back(stack1.top());
            stack1.push(i);
        } else if (!stack1.empty() && A[stack1.top()] >= A[i]) {
            while (!stack1.empty() && A[stack1.top()] >= A[i]) {
                stack1.pop();
            }
            
            i++;
        } else {
            stack1.push(i);
            rightLess.push_back(n);
        }
    }
    
    
    std::reverse(rightLess.begin(), rightLess.end());
    std::reverse(rightMax.begin(), rightMax.end());
    if (debug) {
        printVec(leftMaxEqual);
        printVec(rightMax);
        printVec(leftLessEqual);
        printVec(rightLess);
    }
    ll ans = 0;
    for (int i = 0; i < A.size(); i++) {
        ll freq1 = i - leftMaxEqual[i];
        freq1 *= rightMax[i] - i;
        freq1--;
        
        
        
        ll freq2 = i- leftLessEqual[i];
        freq2 *= rightLess[i] - i;
        freq2--;
        
        if (debug) {
            std::cout << freq1 << " " << freq2 << std::endl;
        }
        ll freq = freq1 - freq2;
        ans += ((freq*A[i])%MOD);
        ans %= MOD;
    }
    if (ans < 0)
        ans += MOD;
    return ans;
    
    
}
