SORTING AND STABILITY:
1. if based on the key 2 elements are similar, then the relative order remains
   same as the original array.


VARIOUS ALGORITHMS:
1. SELECTION SORT:
  Select the ith smallest element during ith iteration of complete array; then
  swap the ith index and this index. 

  STABILITY: The default implementation is NOT STABLE. We can make it stable by
  first getting the right element; and then pushing rest of the elements to the
  right; then copy the element to the its position.

  eg. 4a  4b 2 3 1
  
      getting the smallest element => 1
      pushing the elements to the right

      _ 4a 4b 2 3 

      1 4a 4b 2 3


  DEFAULT IMPLEMENTATION
      4a 4b 2 3 1

      swap(4a and 1) => unstable

      1 4b 2 3 4a



  SWAPS: Maximum swaps can be O(n) in the default implementation. Minimum of
  all sorting algo.


2. BUBBLE SORT

  Swapping every pair of indices iff required. This leads to bubbling of
  smallest element at every iteration.

  STABILITY: Dont swap if elements are equal ensures us the stability.


3. INSERTION SORT
  Insertion sort is simply maintatining two partions ; sorted and unsorted one.
  We basically introduce an element in the sorted list st it maintains the
  order.

  void insertionSort(std::vector<int> vec) {
    for (int i = 1; i < n; i++) {
      //insert the ith element
      int element = A[i];
      int j = i-1;
      while (j >= 0) {
        if (A[j] > element) {
          A[j+1] = A[j];
        } else {
          break;
        }
      }

      A[j+1] = element;
    
    }
  
  }




COMPARISON BETWEEN THESE ALGORITHMS:

1. WORST TIME COMPLEXITY: O(N^2)

2. Number of swaps : O(n) in selection sort; O(n^2) in bubble and insertion
   sort

3. Least time complexity: O(n^2) in selection sort; O(n) in bubble and
   insertion sort; => we dont have to do O(n^2) swaps if array is already
   sorted; this can be determined in one iteration in bubble sort and O(n*1) in
   insertion sort. I.e we only one comparison with last index.




4. DIVIDE AND CONQUER : 

A. merge sort: Divide the array and then merge the sorted arrays. ie. we assume
that smaller portion shall be sorted first and then merge them.


B. STABILITY: this can be achieved at the merging step.


5. Quick Sort:



QUESTIONS

1. Count inversions
2. Reversible pairs [IMPORTANT]




















































