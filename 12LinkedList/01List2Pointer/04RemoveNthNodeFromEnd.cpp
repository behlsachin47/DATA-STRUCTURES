ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* iter1 = A;
    ListNode* pIter2 = nullptr;
    ListNode* iter2 = A;
    ListNode* ans = A;
    
    for (int i = 0; i < B && iter1; i++)
        iter1 = iter1->next;
    
    while (iter1) {
        pIter2 = iter2;
        iter2 = iter2->next;
        iter1 = iter1->next;
    }
    
    if (pIter2 == nullptr) {
        ans = A->next;
        delete A;
    } else {
        pIter2->next = iter2->next;
        delete iter2;
        ans = A;
    }
    
    return ans;
}