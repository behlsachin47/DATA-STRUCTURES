
typedef long long ll;
void nextLargerElement(long long arr[], int n){
    std::stack<ll>* stack1 = new stack<ll>;
    std::vector<ll>* result = new vector<ll>;
    
    for (int i = n-1; i >= 0; i--) {
        while (!stack1->empty() && stack1->top() <= arr[i]) {
            stack1->pop();
        }
        
        if (stack1->empty()) {
            stack1->push(arr[i]);
            result->push_back(-1);
        } else {
            result->push_back(stack1->top());
            stack1->push(arr[i]);
        }
    }
    
    for (int i = result->size()-1; i >= 0; i--) {
        std::cout << result->at(i) << " ";
    }
    
    delete stack1;
    delete result;
    // Your code here
}


/*
    THIS IS QUITE SIMILAR TO STCOKSPAN PROBLEM;
    WHERE WE HAVE TO FIND NEXT GREATER ELEMENT ON LEFT SIDE OF ARRAY
    
*/
