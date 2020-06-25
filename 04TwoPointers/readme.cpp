TWO POINTERS : 
  1. Physical significance of the pointer. They can represent a pair; a range
     etc.
  2. initialize the pointers. (why this initialization ??)
  3. How to move the pointers (reason )

  => Initialization and move pointers in such way that you are able to make
  a concrete decision.


OTHER INTERESTING QUESTIONS:
1. THREE SUM:
	a. Find a triplet that sums closes to a given target.
	b. Find all unique triplets that sums to zero/target.
2. Couting triangles/RECTANGLES.
	Given an array; count all triangles possible with these sides.
3. Remmove duplicates if it exceeds greater than 2.
4. Max continuous series of 1's.
5. Sort 0,1,2.
6. Merge k sorted Linked List


SAMPLE QUESTIONS:

1. Given a sorted and distinct array, find count  distinct integers that sum up to a particular
   number.

   Here if we choose two pointers; one with index = 0 and other index = n-1.
   Now if we increase pointer st; we will be increasing the sum; and if we
   decrease end pointer we will be decreasing the sum. Hence we are able to
   make a concrete decision. :)


   FOLLOW UP QUESTION: What if integers are not distinct ??
   
   
   
   => This becomes a little complicated. Basically when arr[st] + arr[end] ==
   k; we need to first check if arr[st] == arr[end]; if yes => we need to have
   the freq of this element and add the n*(n-1)/2 to the answer; if no => we
   need to count freq of arr[st] and arr[end] element and have the ans += frq1
   * frq2;
  

/* Given a sorted array with distinct integers. Find the number of pairs that
 * add to the given sum k.
 *
 *
 * */


int countPairs(const std::vector<int>& vec, int k) {
  int ptr1 = 0;
  int ptr2 = vec.size()-1;
  int ans = 0;

  while (ptr1 < ptr2) {
    if (vec[ptr1] + vec[ptr2] == k) {
      ans++;
      ptr1++;
      ptr2++;
    } else if (vec[ptr1] + vec[ptr2] > k) {
      ptr2--;
    } else {
      ptr1++;
    }
  }

  return ans;

}



/* What if repeated integers. That is not distinct.
 *
 * */

int countPairs(const std::vectir<int>& vec, int k) {
  int ptr1 = 0;
  int ptr2 = vec.size()-1;
  int ans = 0;

  while (ptr1 < ptr2) {
    if (vec[ptr1] + vec[ptr2] == k) {
      if (vec[ptr1] != vec[ptr2]) {
        int count1 = 1;
        int count2 = 1;
        while (vec[ptr1] == vec[ptr1+1]) {
          ptr1++;
          count1++;
        }
        
        while (vec[ptr2] == vec[ptr2+1]) {
          ptr2++;
          count2++;
        }

        ptr1++;
        ptr2++;
        
        ans += (count1 * count2);

      } else {
        int count = ptr2-ptr1+1;
        ans += (n*(n-1))/2;
        break;
      } 

    } else if (vec[ptr1] + vec[ptr2] > k) {
      ptr2--;
    } else {
      ptr1++;
    }
  
  }

  return ans;

}


2. DIFFk
  


/* Number of diffk possible. We have to find out how many pairs exist such that
 * diff is k.
 *
 * Lets consider distinct integers for now.
 *
 * ptr1 - ptr2 = k'
 *
 * Now how do we choose ptr1 and ptr2 such that we are able to make the
 * concrete decision of either reducing k' or increasing k'
 *
 * if we have to increase k': what are our options; increase ptr1 and decrease
 * ptr2
 *
 * if we have to decrease k' : what are our options; decrease ptr1 and increase
 * ptr2
 *
 * so we should not move the two pointers in the same directions. Instead lets
 * say we consider two cases:
 *  CASE1:Increase ptr1; increase ptr2
 *  CASE2:dECREASE ptr1; decrease ptr1
 * */
#include <iostream>
#include <vector>

//case1
int countDiffK(const std::vector<int>& vec, int k) {
  int n = vec.size();
  int ptr1 = 1;
  int ptr2 = 0;
  int ans = 0;
  while (ptr1 < n) {
    if (vec[ptr1] - vec[ptr2] == k) {
      ans++;
      ptr1++;
      ptr2++;
    } else if (vec[ptr1] - vec[ptr2] > k) {
      ptr2++;
    } else {
      ptr1++;
    }

    if (ptr1 == ptr2) {
      ptr1++;
    }
  
  }

  return ans;

}



//repeated elements
//

int countDiffK2(const std::vector<int>& vec, int k) {
  int n = vec.size();
  int ptr1 = 1;
  int ptr2 = 0;
  int ans = 0;
  while (ptr1 < n) {
    if (vec[ptr1] - vec[ptr2] == k) {
      if (vec[ptr1] == vec[ptr2]) {
        int count = 1;
        while (ptr2+1 < n && vec[ptr2+1] == vec[ptr2]) {
          ptr2++;
          count++;
        }

        ans += (count*(count-1))/2;
        ptr1 = ptr2+1;

      } else {
        int count1 = 1;
        int count2 = 1;
        while (ptr1+1 < n && vec[ptr1] == vec[ptr1+1]) {
          count1++;
          ptr1++;
        }

        while ( vec[ptr2] == vec[ptr2+1]) {
          count2++;
          ptr2++;
        }

        ans += count1*count2;
        ptr1++;
        ptr2++;
      }

    } else if (vec[ptr1] - vec[ptr2] > k) {
      ptr2++;
    } else {
      ptr1++;
    }

    if (ptr1 == ptr2) {
      ptr1++;
    }
  
  }

  return ans;

}



int main() {
  std::vector<int> vec = {1,1,1, 2,2,2,3,3,4,4,4,5,5,6,6};
  std::cout << countDiffK2(vec, 1) << std::endl;

}



3. MINIMIZE THE ABSOLUTE DIFF




/*Array 3 Pointers
Problem Description
You are given 3 sorted arrays A, B and C. Find i, j, k such that : max(abs(A[i]
- B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized. Return the minimum
  max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])).   


  Problem Constraints
  0 <= len(A), len(B), len(c) <= 106 0 <= A[i], B[i], C[i] <= 107    


  Input Format
  First argument is an integer array A. Second argument is an integer array B.
  Third argument is an integer array C.    


  Output Format
  Return an single integer denoting the minimum max(abs(A[i] - B[j]), abs(B[j]
  - C[k]), abs(C[k] - A[i])).


    Example Input*/


int Solution::minimize(const vector<int> &A, const vector<int> &B, const
vector<int> &C) {
    int pt1 = 0;
    int pt2 = 0;
    int pt3 = 0;
    int ans = INT_MAX;
    while (pt1 < A.size() && pt2 < B.size() && pt3 < C.size()) {
        int maxElement = std::max(A[pt1], std::max(B[pt2], C[pt3]));
        int minElement = std::min(A[pt1], std::min(B[pt2], C[pt3]));
        ans = std::min(ans, maxElement-minElement);
        
        if (minElement == A[pt1]) 
            pt1++;
        else if (minElement == B[pt2])
            pt2++;
        else 
            pt3++;
    }
    
    return ans;
}




4. SLIDING WINDOW AND TWO POINTERS:
 
4. Given an array with positive elements; we have to find all subarray with sum = k

Given an array with positive elements; we have to find if there exists
   a subarray with sum = k


vector<int> Solution::solve(vector<int> &A, int B) {
    //now as arrays contains only positive elements
    //so two pointer approach can work here.
    //if we consider ptr1 and ptr2; as start and ends of a window
    //increasing ptr1 shall decrease the sum for sure (not sure if there were negative elements 
    //the array.)
    
    int ptr1 = 0;
    int ptr2 = 0;
    //window => ptr1 to ptr2
    std::vector<int> output;
    
    if (A.size() == 0)
        return output;
        
    int currSum = A[ptr1];
    
    while (ptr2 < A.size()) {
        //move window accordingly
        if (currSum == B) {
            //ptr1 to ptr2 window is valid :)
            break;
        } else if (currSum > B) {
            //lets decrease one element and see
            currSum -= A[ptr1];
            ptr1++;
        } else {
            ptr2++;
            currSum += A[ptr2];
        }
        
    }
    
    if (ptr2 == A.size()) {
        output.push_back(-1);
    } else {
        for (int i = ptr1; i <= ptr2; i++)
            output.push_back(A[i]);
    }
    
    return output;
    
}




5. CONTAINER WITH MOST WATER

typedef long long ll;

int Solution::maxArea(vector<int> &A) {
    int ans = 0;
    int ptr1 = 0;
    int ptr2 = A.size()-1;
    while (ptr1 < ptr2) {
        int h = std::min(A[ptr1], A[ptr2]);
        ans = std::max((ptr2-ptr1+1)*h, ans);
        if (h == A[ptr1])
            ptr1++;
        else
            ptr2--;
    }
    
    return ans;
}


