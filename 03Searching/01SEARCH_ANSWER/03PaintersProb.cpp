typedef long long ll;
#include <numeric>
ll MOD = 10000003;
bool isPossible(int A, std::vector<int>& arr, int ans) {
    int count = 1;
    int currPainted = 0;
    for (int i = 0; i < arr.size(); i++) {
        currPainted += arr[i];
        if (currPainted > ans) {
            count++;
            currPainted = arr[i];
        } 
    }
    
    if (count > A)
        return false;
    
    return true;
}

int Solution::paint(int A, int B, vector<int> &C) {
    if (A <= 0)
        return -1;
        
    ll lowAns = *std::max_element(C.begin(), C.end()); 
    ll highAns = std::accumulate(C.begin(), C.end(), 0);
    
    ll ans = lowAns;
    while (lowAns <= highAns) {
      ll mid = lowAns + (highAns-lowAns)/2;
      if (isPossible(A, C, mid)) {
          ans = mid;
          highAns = mid-1;
      } else {
          lowAns = mid+1;
      }
    }
    ans = ans % MOD;
    ans = (ans*B)%MOD;
    return ans;
}

