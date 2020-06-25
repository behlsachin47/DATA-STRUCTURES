typedef long long ll;
#include <numeric>
bool isPossibleWithAtMostBstudents(std::vector<int>& arr, ll numStudents, ll
maxPages) {
    ll count = 1;
    ll currPages = 0;
    for (int i = 0; i < arr.size(); i++) {
        currPages += arr[i];
        if (currPages > maxPages) {
            count++;
            currPages = arr[i];
        }
    }
    
    if (count > numStudents)
        return false;
    return true;
}

int Solution::books(vector<int> &A, int B) {
    if (A.size() < B)
        return -1;
        
    ll lowAns = *std::max_element(A.begin(), A.end());
    ll highAns = std::accumulate(A.begin(), A.end(), 0);
    ll ans = lowAns;
    while (lowAns <= highAns) {
        ll mid = lowAns + (highAns-lowAns)/2;
        
        if (isPossibleWithAtMostBstudents(A, B, mid)) {
            ans = mid;
            highAns = mid-1;
        } else {
            lowAns = mid+1;
        }
    }
    
    return ans;
}

