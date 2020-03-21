typedef long long ll;
typedef std::pair<ll, ll> iPair;
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        bool debug = 0;
    int n = arr.size();
        if (n == 0)
            return 0;
    // Your code here
    std::stack<iPair> stack1; 
    //left smaller elements
    std::stack<iPair> stack2;
    
    ll* arr1 = new ll[n];
    ll* arr2 = new ll[n];
    
    for (int i = 0; i < n; i++) {
        while (!stack1.empty() && stack1.top().first >= arr[i])
            stack1.pop();
        
        if (stack1.empty() == true) {
            arr1[i] = (i+1)*arr[i];
            stack1.push(std::make_pair(arr[i], i));
        } else {
            arr1[i] = (i-stack1.top().second)*arr[i];
            stack1.push(std::make_pair(arr[i], i));
        }
    }
    
    for (int i = n-1; i >= 0; i--) {
        while (!stack2.empty() && stack2.top().first >= arr[i]) {
            stack2.pop();
        }
        
        if (stack2.empty() == true) {
            arr2[i] = (n-i)*arr[i];
            stack2.push(std::make_pair(arr[i], i));
        }  else {
            arr2[i] = (stack2.top().second-i)* arr[i];
            stack2.push(std::make_pair(arr[i], i));
        }
    }
    
    ll ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (ans < (arr1[i] + arr2[i]-arr[i]))
            ans = arr1[i] + arr2[i] -arr[i];
    }
    
    if (debug) {
        for (int i = 0; i < n; i++) {
            std::cout << arr1[i] << "; " << arr2[i] << std::endl;
        }
    }
    delete[] arr1;
    delete[] arr2;
    
    return ans;
    
    }
};