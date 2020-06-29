class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        //std::sort(arr.begin(), arr.end());
        int ans = 0;
        while(arr.size() != 1) {
            int smallIndex1 = -1;
            
            int product = INT_MAX;
            for (int i = 0; i < arr.size()-1; i++) {
                if (product > arr[i]* arr[i+1]) {
                    smallIndex1 = i;
                    product = arr[i]* arr[i+1];
                }
            }
            
            ans += product;
            //std::vector<int> tempArr;

            for (int i = 0, j = 0; i < arr.size(); i++) {
                if (i == smallIndex1) {
                    arr[j++] = std::max(arr[i], arr[i+1]);
                    i++;
                } else {
                    arr[j++] = arr[i];
                }
            }
            arr.pop_back();
        }
        return ans;
    }
};