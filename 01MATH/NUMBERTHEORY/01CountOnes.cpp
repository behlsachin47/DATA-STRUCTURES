typedef long long ll;
ll countDigitOneUtil(ll n, ll numDig) {
    if (numDig == 1) {
        if (n == 0)
            return 0;
        else
            return 1;
    }
    
    ll power = pow(10, numDig-1);
    ll firstDig = n/power;
    
    if (firstDig == 0)
        return countDigitOneUtil(n%power, numDig-1);
    else if (firstDig == 1)
        return (numDig-1)*power/10 + n%power + 1 + countDigitOneUtil(n%power,
numDig-1);
    else
        return firstDig *(numDig-1)*power/10 + power
+ countDigitOneUtil(n%power, numDig-1);
}
class Solution {
public:
    int countDigitOne(int n) {
        if ( n <= 0)
            return 0;
        int numDig = log10(n)+1;
        return countDigitOneUtil(n, numDig);
    }
};
