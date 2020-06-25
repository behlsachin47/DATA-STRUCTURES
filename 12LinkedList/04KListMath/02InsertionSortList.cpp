/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode* sortedHead = nullptr;
    ListNode* iter = A;
    
    while (A) {
        if (sortedHead == nullptr) {
            sortedHead = A;
            A = A->next;
            sortedHead->next = nullptr;
        } else {
            ListNode* iter = sortedHead;
            ListNode* pIter = nullptr;
            
            while (iter && iter-> val < A->val) {
                pIter = iter;
                iter = iter->next;
            }
            ListNode* temp = A->next;
            if (!pIter) {
                //insertion at sorted Head
                
                A->next = sortedHead;
                sortedHead = A;
               
            } else {
                pIter->next = A;
                A->next = iter;
            }
            
            A = temp;
        }
    }
    
    return sortedHead;
}
