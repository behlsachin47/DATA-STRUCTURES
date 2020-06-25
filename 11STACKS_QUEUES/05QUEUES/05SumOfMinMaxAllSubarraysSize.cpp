typedef long long ll;
ll MOD = 1000000007;
int Solution::solve(vector<int> &A, int B) {
    bool debug = 0;
    //FIRST COMPUTE SUM OF ALL MAX ELEMENTS
    ll maxSum = 0;
    std::deque<int> dq;
    
    for (int i = 0; i < A.size() && i < B; i++) {
        if (!dq.empty() && A[dq.back()] >= A[i]) {
            dq.push_back(i);
        } else if (!dq.empty()) {
            while (!dq.empty() && A[dq.back()] < A[i]) {
                dq.pop_back();
            }
            i--;
        } else {
            dq.push_back(i);
        }
    }
    maxSum += A[dq.front()];
    maxSum %= MOD;
    
    for (int i = B; i < A.size(); i++) {
        //first remove the first element if thats out of window
        if (dq.front() == i - B)
            dq.pop_front();
        
        if (!dq.empty() && A[dq.back()] >= A[i]) {
            maxSum += A[dq.front()];
            maxSum %= MOD;

            dq.push_back(i);
        } else if (!dq.empty()) {
            while (!dq.empty() && A[dq.back()] < A[i]) {
                dq.pop_back();
            }
            i--;
        } else {
            dq.push_back(i);
            maxSum += A[dq.front()];
            maxSum %= MOD;

        }
        
    }
    
    dq = std::deque<int> ();
    ll minSum = 0;
    for (int i = 0; i < A.size() && i < B; i++) {
        if (!dq.empty() && A[dq.back()] <= A[i]) {
            dq.push_back(i);
        } else if (!dq.empty()) {
            while (!dq.empty() && A[dq.back()] > A[i]) {
                dq.pop_back();
            }
            i--;
        } else {
            dq.push_back(i);
        }
    }
    minSum += A[dq.front()];
    minSum %= MOD;
    
    for (int i = B; i < A.size(); i++) {
        //first remove the first element if thats out of window
        if (dq.front() == i - B)
            dq.pop_front();
        
        if (!dq.empty() && A[dq.back()] <= A[i]) {
            minSum += A[dq.front()];
            minSum %= MOD;

            dq.push_back(i);
        } else if (!dq.empty()) {
            while (!dq.empty() && A[dq.back()] > A[i]) {
                dq.pop_back();
            }
            i--;
        } else {
            dq.push_back(i);
            minSum += A[dq.front()];
            minSum %= MOD;

        }
        
    }
    if (debug) {
        std::cout << maxSum << " " << minSum << std::endl;
    }
    ll ans = maxSum + minSum;
    ans %= MOD;
    if (ans < 0)
        ans += MOD;
        
    return ans;
    
    
}
