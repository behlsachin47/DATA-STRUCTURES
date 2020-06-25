std::stack<int> stack1;
std::stack<int> stack2; //min values
MinStack::MinStack() {
    stack1 = std::stack<int> () ;
    stack2 = std::stack<int> {}; //min values
}



void MinStack::push(int x) {
    stack1.push(x);
    
    if (stack2.size()) {
        if (stack2.top() >= x)
            stack2.push(x);
    } else {
        stack2.push(x);
    }
}

void MinStack::pop() {
    if (stack1.size() == 0)
        return;
    else if (stack1.top() == stack2.top()) {
        stack1.pop();
        stack2.pop();
    } else {
        stack1.pop();
    }
    
}

int MinStack::top() {
    
    if (stack1.empty())
        return -1;
    else 
        return stack1.top();
}

int MinStack::getMin() {
    if(stack2.empty())
        return -1;
    
    return stack2.top();
}

