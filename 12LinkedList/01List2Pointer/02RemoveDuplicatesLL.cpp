ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* iter = A;
    while (iter) {
        ListNode* pIter2 = nullptr;
        ListNode* iter2 = iter->next;
        while (iter2 && iter->val == iter2->val) {
            delete pIter2;
            pIter2 = iter2;
            iter2 = iter2->next;
        }
        delete pIter2;
        iter->next = iter2;
        iter = iter2;
    }
    
    return A;
}