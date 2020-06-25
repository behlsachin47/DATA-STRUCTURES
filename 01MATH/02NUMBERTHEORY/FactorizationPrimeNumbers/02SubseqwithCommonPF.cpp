/*
 * Groot has an array A of size N. Boring right? Groot thought so too, so he
decided to construct another array B of the same size and defined elements of
B as: B[i] = factorial of A[i] for every i such that 1<= i <= N.    
factorial of a number X denotes (1 x 2 x 3 x 4......(X-1) x (X)).
 Now Groot is interested in the total number of non-empty subsequences of array
B such that every element in the subsequence has the same non empty set of
prime factors. Since the number can be very large, return it modulo 109 + 7.
NOTE: A set is a data structure having only distinct elements. Eg : the set of
prime factors of Y=12 will be {2,3} and not {2,2,3}    


Problem Constraints
1 <= N <= 105
1 <= A[i] <= 106
Your code will run against a maximum of 5 test cases.


Input Format
Only argument is an integer array A of size N.


Output Format
Return an integer deonting the total number of non-empty subsequences of array
B such that every element in the subsequence has the same set of prime factors
modulo 109+7.


Example Input
Input 1:
 A = [2, 3, 2, 3]
Input 2:
 A = [2, 3, 4]
   


Example Output
Output 1:
 6
Output 2:
 4

*/



int MOD = 1000000007;
typedef long long ll;
int Solution::solve(vector<int> &A) {
    if (A.size() <= 1)
        return A.size();
    int maxElement = A[0];
    for (ll i = 1; i < A.size(); i++) 
        maxElement = std::max(maxElement, A[i]);
    
    std::vector<ll> sieve(maxElement+1, 0);
    for (ll i = 0; i <= maxElement; i++) {
        sieve[i] = i;
    }
    
    int lastPF = 2;
    for (ll i = 2; i <= maxElement; i++) {
        if (sieve[i] == i) {
            for (ll j = i*i; j <= maxElement; j += i) {
                sieve[j] = i;
            } 
            lastPF = i;
        } else {
            sieve[i] = lastPF;
        }
    }
    
    std::unordered_map<ll, ll> myMap;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == 1)
            continue;
        lastPF = sieve[A[i]];

        if (myMap.count(lastPF)) {
            myMap[lastPF]++;
        } else {
            myMap.insert({lastPF, 1});
        }
    }
    ll ans = 0;
    for (auto iter = myMap.begin(); iter != myMap.end(); iter++) {
        ans += pow(2, iter->second)-1;
        ans %= MOD;
    }
    return ans;
}

