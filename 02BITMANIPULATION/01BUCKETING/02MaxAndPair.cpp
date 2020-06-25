int maxAND (int arr[], int n)
{
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if ((ans & arr[j]) == ans && (arr[j] & (1 << i)) ) {
                count++;
            }
        }
        
        if (count >= 2) {
            ans |= (1 << i);
        }
    }
    
    return ans;
}
