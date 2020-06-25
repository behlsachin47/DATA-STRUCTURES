1. SELECTION SORT: 
  Simply store the largest and put it at the end. Least swapping.

2. BUBBLE SORT:
  Simply do swapping of adjacent elements, n-1 times

3. INSERTION SORT:
  Insert the element to alread sorted sub array.

  void insertionSort(std::vector<int>& arr) {
    for (int i = 1; i < n; i++) {
      
      int num = arr[i];
      int j = i-1;
      
      while (j >= 0 && arr[j] > num) {
        arr[j+1] = arr[j];
        j--;
      }
      arr[j+1] = num;
    
    }
  }

4. Merge sort

  DIVIDE AND CONQUER
  MERGING STEP: takes O(N+M) time and O(N+M) space 


