/*Problem Description
There are N players each with strength A[i]. when player i attack player j,
player j strength reduces to max(0, A[j]-A[i]). When a player's strength
reaches zero, it loses the game and the game continues in the same manner among
other players until only 1 survivor remains.

Can you tell the minimum health last surviving person can have?


Problem Constraints
1 <= N <= 100000
1 <= A[i] <= 1000000


Input Format
First and only argument of input contains a single integer array A.


Output Format
Return a single integer denoting minimum health of last person.


Example Input
Input 1:
 A = [6, 4]
Input 2:
 A = [2, 3, 4]
     


Example Output
Output 1:
 2
Output 2:
 1
*/

int Solution::gcd(int A, int B) {
}
int gcd(int A, int B) {
    if (B == 0)
        return A;
    else 
        return gcd(B, A%B);
}
int Solution::solve(vector<int> &A) {
    if (A.size() == 0)
        return 0;
        
    int g = A[0];
    for (int i = 1; i < A.size(); i++)
        g = gcd(g, A[i]);
    
    return g;
}

