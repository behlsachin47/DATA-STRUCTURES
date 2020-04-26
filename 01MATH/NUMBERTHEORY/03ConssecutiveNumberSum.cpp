bool checkIFpossible (int m, int N) {
    int num = 2*N;
    if (num % m != 0)
        return false;
    num = num/m;
    num = num-m+1;
    if (num % 2 != 0)
        return 0;
    return true;
}
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int count = 0;
        for (int i = 1; i <= sqrt(2*N); i++) {
            if(checkIFpossible(i, N))
                count++;
        }
        
        
        return count;
    }
};
