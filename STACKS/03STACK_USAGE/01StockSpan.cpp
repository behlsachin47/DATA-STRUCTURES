typedef pair<int, int> iPair;
void calculateSpan(int price[], int n, int S[])
{
    if (n == 0)
        return;
        
   std::stack<iPair> stack1;
   
   for (int i = 0; i < n; i++) {
       
        while (stack1.empty() == false && stack1.top().first <= price[i])
          stack1.pop();
       if (stack1.empty() == true) {
           S[i] = i + 1;
           stack1.push(std::make_pair(price[i], i));
       } else {
            S[i] = i-stack1.top().second;
            stack1.push(std::make_pair(price[i], i));
       }
   }
   
}


/*
    STOCK SPAN
    basic idea is to keep those elements in the stack that are greater
    than current element. 

    No point in storing smaller elements as they will be blocked by 
    current element.

    
*/