/*
Compare Sorted Subarrays
Problem Description

Given an array A of length N. You have to answer Q queires.

Each query will contain 4 integers l1, r1, l2 and r2. If sorted segment from [l1, r1] is same as sorted segment from [l2 r2] then answer is 1 else 0.

NOTE The queries are 0-indexed.



Problem Constraints
0 <= A[i] <= 100000
1 <= N <= 100000
1 <= Q <= 100000



Input Format
First argument is an array A.
Second will be 2-D array B denoting queries with dimension Q * 4.
Consider ith query as l1 = B[i][0], r1 = B[i][1], l2 = A[i][2], r2 = B[i][3].



Output Format
Return an array of length Q with answer of the queries in the same order in input.



Example Input
Input 1:

 A = [1, 7, 11, 8, 11, 7, 1]
 B = [ 
       [0, 2, 4, 6]
     ]
Input 2:

 A = [1, 3, 2]
 B = [
       [0, 1, 1, 2]
     ] 


Example Output
Output 1:

 [1]
Output 2:

 [0]


Example Explanation
Explanation 1:

 (0, 2) -> [1, 7, 11]
 (4, 6) -> [11, 7, 1]
 Both are same when sorted hence 1.
Explanation 2:

 (0, 1) -> [1, 3]
 (1, 2) -> [3, 2] 
 Both are different when sorted hence -1.
*/


vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    std::vector<int> prefixXor(A.size(), 0);
        std::vector<int> result;
        prefixXor[0] = A[0];
        for (int i = 1; i < A.size(); i++) {
            prefixXor[i] = prefixXor[i-1]^A[i];
        }
    for (int i = 0; i < B.size(); i++) {
        int l1 = B[i][0];
        int r1 = B[i][1];
        int l2 = B[i][2];
        int r2 = B[i][3];
        
        
        if (l1 == l2 && r1 == r2) {
            result.push_back(1);
        } else if (r1-l1 != r2-l2 ){
            result.push_back(0);
        } else {
            int xor1;
            int xor2;
            
            if (l1 == 0) {
                xor1 = prefixXor[r1];
            } else {
                xor1 = prefixXor[r1] ^ prefixXor[l1-1];
            }
            
            if (l2 == 0) {
                xor2 = prefixXor[r2];
            } else {
                xor2 = prefixXor[r2] ^ prefixXor[l2-1];
            }
            
            if (xor1 == xor2) {
                int ans = 1;
                //result.push_back(1);
                std::unordered_map<int, int> map1;
                std::unordered_map<int, int> map2;
                for (int i = l1; i <= r1; i++) {
                    if (map1.count(A[i])) {
                        map1[A[i]]++;
                    } else {
                        map1.insert({A[i], 1});
                    }
                }
                
                for (int i = l2; i <= r2; i++) {
                    if (map1.count(A[i]) == 0) {
                        ans = 0;
                        break;
                    }
                    
                    if (map2.count(A[i])) {
                        if (map2[A[i]] == map1[A[i]])
                        {
                            ans = 0;
                            break;
                        } else {
                            map2[A[i]]++;
                        }
                    } else {
                        map2.insert({A[i], 1});
                    }
                }
                result.push_back(ans);
            } else {
                result.push_back(0);
            }
        }
    }
    return result;
}
