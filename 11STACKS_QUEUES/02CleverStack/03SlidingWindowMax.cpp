vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    std::stack<int> stack1;
    std::vector<int> rightLargestIndex;
    bool debug =0 ;
    for (int i = A.size() - 1; i >= 0; i--) {
        if (stack1.empty()) {
            rightLargestIndex.push_back(-1);
            stack1.push(i);
        } else if (A[stack1.top()] > A[i]) {
            rightLargestIndex.push_back(stack1.top());
            stack1.push(i);
        } else {
            while (stack1.size() && A[stack1.top()] <= A[i]) {
                stack1.pop();
            }
            i++;
        }
    }
    std::reverse(rightLargestIndex.begin(), rightLargestIndex.end());
    
    if (debug) {
        for (int i = 0; i < rightLargestIndex.size(); i++)
            std::cout << rightLargestIndex[i] << " ";
        std::cout << std::endl;
    }
    std::vector<int> output;
    for (int i = 0; i <= A.size() - B; i++) {
        if (i == 0) {
            if (rightLargestIndex[i] == -1 || rightLargestIndex[i] >= i + B) {
                output.push_back(i);
            } else  {
                int j = i;
                int prevJ = i;
                while (rightLargestIndex[j] != -1 && j < i + B) {
                    prevJ = j;
                    j = rightLargestIndex[j];
                }
                
                if (j >= i+ B) {
                    output.push_back(prevJ);
                } else {
                    output.push_back(j);
                }
            }
        } else {
            int j = i; // assuming ith element is larges
            if (output.back() > j ) {
                j = output.back();
            }
            
            //now go till rightLargestIndex[j] != -1 
            // and j < i + B
            int prevJ = j;
            while (rightLargestIndex[j] != -1 && j < i + B) {
                prevJ = j;
                j = rightLargestIndex[j];
            }
            
            if (j >= i+ B) {
                output.push_back(prevJ);
            } else {
                output.push_back(j);
            }
        }
        
    }
    
    for (int i = 0; i < output.size(); i++) {
        //std::cout << output[i] << " ";
        output[i] = A[output[i]];
        
        
    }
    return output;
}
