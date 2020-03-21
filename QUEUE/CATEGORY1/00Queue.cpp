#include <iostream>

template<typename T>
class Queue {
    T* arr;
    int size;
    int front;
    int end;
    int capacity;
public:
    Queue() :arr(nullptr), size(0), front(-1), end(-1), capacity(0) {}
    
    void push(T x) {
        if (size == capacity) {
            int newCapacity = 2* capacity;
            if (capacity == 0) {
                newCapacity = 1;
            } 
            T* newArr = new T[newCapacity];
            for (int i = 0; i < capacity; i++) {
                newArr[i] = arr[(front+i)%capacity];
            }
            front = 0;
            end = capacity-1;
            capacity = newCapacity;
            delete[] arr;
            arr= newArr;
        } 
        
        arr[(end+1) % capacity ] = x;
        end++;
        size++;
    }
    
    void pop() {
        end--;
        size--;
    }
    
    T top() {
        return arr[(end)%capacity];
    }
    
    bool empty() {
        if (size == 0)  
            return 1;
        return 0;
    }
    
    void display() {
        std::cout << "front: " << front << " end: " << end << " size: " << size 
            << "capacity: " << capacity << std::endl;
    }
};


int main() {
    Queue<int> q;
    q.push(100);
    q.display();
    q.push(200);
    q.display();
    q.push(300);
    q.display();
    q.push(400);
    q.display();
    q.push(500);
    q.display();
    
    while (!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    return 0;
}