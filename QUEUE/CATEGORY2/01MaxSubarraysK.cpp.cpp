#include <iostream>
#include <unordered_map>
using namespace std;
bool debug = 0;
class maxHeap {
    int* heapArr;
    int* arr;
    int size;
    public:
        std::unordered_map<int, int> mapArrHeapIndex; //array index and binHeap index

    void swap(int ind1, int ind2) {
        
        int temp = heapArr[ind1];
        heapArr[ind1] = heapArr[ind2];
        heapArr[ind2] = temp;
        
        mapArrHeapIndex[heapArr[ind1]] = ind1;
        mapArrHeapIndex[heapArr[ind2]] = ind2;
        
        
    }
    
    void downHeapify(int index) {
        int largest = index;
        int child1 = 2*index + 1;
        int child2 = 2*index + 2;
        
        if (child1 < size && arr[heapArr[child1]] > arr[heapArr[largest]])
        {
            largest = child1;
        }
        
        if (child2 < size && arr[heapArr[child2]] > arr[heapArr[largest]]) {
            largest = child2;
        }
        
        if (largest != index) {
            swap(largest, index);
            downHeapify(largest);
        }
    }
    
    void upHeapify(int index) {
        if (debug)
            std::cout << "upheapify called for " << arr[heapArr[index]] << std::endl;
        if (index == 0)
            return ;
        
        int parentIndex = (index-1)/2;
        if (arr[heapArr[parentIndex]] < arr[heapArr[index]]) {
            swap(index, parentIndex);
            upHeapify(parentIndex);
        }
    }
public:

    
    maxHeap(int* arr, int size) : arr(arr),heapArr(nullptr), size(size) {
        heapArr = new int[size];
        for (int i = 0; i < size; i++) {
            heapArr[i] = i;
            mapArrHeapIndex.insert({i, i});
        }
        //dont call anything for leaf nodes as they are already forming a heap
        for (int i = size/2; i >= 0; i--) {
            downHeapify(i);
        }
    }
    
    int getMax() {
        return arr[heapArr[0]];
    }
    
    void deleteIndex(int arrIndex) {
        if (debug) {
            std::cout << "deletion for " << arr[arrIndex] << " called\n";
        }
        int heapIndex = mapArrHeapIndex[arrIndex];
        swap(heapIndex, size-1);
        size--;
        downHeapify(heapIndex);
        mapArrHeapIndex.erase(arrIndex);
    }
    
    void insertIndex(int arrIndex) {
        if (debug)
        std::cout << "insertion for " << arr[arrIndex] << " called\n";
        size++;
        heapArr[size-1] = arrIndex;
        mapArrHeapIndex.insert({arrIndex, size-1});
        upHeapify(size-1);
    }
    
    
};

void max_of_subarrays(int *arr, int n, int k){
    maxHeap m(arr, k);
    for (int i = k; i < n; i++) {
        std::cout << m.getMax() << " ";
        m.deleteIndex(i-k);

        if (debug) {
            std::cout << "deletion " << std::endl;
            std::cout << "arrIndex : heapIndex " << std::endl;
            for (auto iter = m.mapArrHeapIndex.begin(); iter != m.mapArrHeapIndex.end(); iter++) {
                std::cout << iter->first << "  :  " << iter->second << std::endl;
            }
            std::cout << "\n\n";
        }
        m.insertIndex(i);
        if (debug) {
            std::cout << "insertion " << std::endl;
            std::cout << "arrIndex : heapIndex " << std::endl;
            for (auto iter = m.mapArrHeapIndex.begin(); iter != m.mapArrHeapIndex.end(); iter++) {
                std::cout << iter->first << "  :  " << iter->second << std::endl;
            }
            std::cout << "\n\n";
        }
    }
    std::cout << m.getMax() << " ";
    // your code here
}

int main() {
    int arr[10] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int n = 10;
    int k = 4;

    max_of_subarrays(arr, n, k);
}