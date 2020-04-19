#include "../../headers.h"

class Stack {
  int* arr;
  int size;
  int top;
public:
  Stack(): arr(new int[1]), size(1), top(0) {}
  //copy constructor

  Stack(const Stack& other) {
    std::cout << "copy constructor called\n";
    size = other.size;
    arr = new int[size];
    top = other.top;

    for (int i = 0; i < size; i++)
      arr[i] = other.arr[i];

  }

  Stack& operator= (const Stack& other) {
    std::cout << "assignment operator called\n";
    if (this == &other) 
      return *this;

    delete[] arr;
    
    size = other.size;
    arr = new int[size];
    top = other.top;

    for (int i = 0; i < size; i++)
      arr[i] = other.arr[i];
  }


  //move constructor
  Stack(Stack&& other) {
    std::cout << "move constructor called\n";
    //steal and nulls. 
    arr = other.arr;
    size = other.size;
    top = other.top;

    other.arr = nullptr;
    other.size = 0;
    other.top = -1;
  }

  //move assignment operator
  Stack& operator=(Stack&& other) {
    std::cout << "move assignment operator called \n";
    //first check
    if (this ==  &other)
      return *this;

    //deletes
    delete[] arr;
    arr = other.arr;
    size = other.size;
    top = other.top;

    other.arr = nullptr;
    other.size = 0;
    other.top = -1;

    return *this;
  }

  void push(int val) {
    if (top == size) {
      int* newArr = new int[2*size];
      for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
      }
      delete[] arr;
      arr = newArr;
      size = 2*size;
    }

    arr[top++] = val;
  }

  void pop() {
    if (Stack::isEmpty()) {
      std::cerr << "Stack empty\n";
      return;
    }
    top--;
  }

  int GetTop() {
    if (Stack::isEmpty())
      return -1;

    return arr[top-1];
  }
  

  bool isEmpty() {
    if (top <= 0)
      return 1;
    return 0;
  }

  ~Stack() {
    delete[] arr;
    arr = nullptr;
    size = 0;
    top = -1;
  }

  
};

Stack getNewStack() {
  Stack temp;
  return temp;
}

int main() {
  Stack st1;
  st1.push(100);
  st1.push(200);
  st1.push(300);
  st1.push(400);
  st1.push(500);
  st1.push(600);
  st1.push(700);

  Stack st2 (st1);

  Stack st3 = getNewStack();
  
  st2 = st1;

  while (!st1.isEmpty()) {
    std::cout << st1.GetTop() << " ";
    st1.pop();
  }
  std::cout << std::endl;

  while (!st2.isEmpty()) {
    std::cout << st2.GetTop() << " ";
    st2.pop();
  }
  std::cout << std::endl;
  
  while (!st3.isEmpty()) {
    std::cout << st3.GetTop() << " ";
    st3.pop();
  }
  std::cout << std::endl;


  st3 = st1;
  st1 = getNewStack();
}
