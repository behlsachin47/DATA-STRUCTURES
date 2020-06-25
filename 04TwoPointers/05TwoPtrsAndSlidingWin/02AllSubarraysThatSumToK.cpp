vector<int> Solution::solve(vector<int> &A, int B) {
    //now as arrays contains only positive elements
    //so two pointer approach can work here.
    //if we consider ptr1 and ptr2; as start and ends of a window
    //increasing ptr1 shall decrease the sum for sure (not sure if there were negative elements 
    //the array.)
    
    int ptr1 = 0;
    int ptr2 = 0;
    bool flag = 0;
    //window => ptr1 to ptr2
    std::vector<int> output;
    
    if (A.size() == 0)
        return output;
        
    int currSum = 0;
    
    while (ptr2 < A.size()) {
        currSum += A[ptr2];
        
        if (currSum >= B) {
            while (currSum >= B) {
                if (currSum == B) {
                    flag = true;
                    break;
                } else {
                    currSum -= A[ptr1];
                    ptr1++;
                }
            }
        }
        if (flag)
            break;
        ptr2++;
        
        
        
    }
    
    if (ptr2 == A.size()) {
        output.push_back(-1);
    } else {
        for (int i = ptr1; i <= ptr2; i++)
            output.push_back(A[i]);
    }
    
    return output;
    
}
