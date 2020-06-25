/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if (A == nullptr || A->next == nullptr)
        return A;
    
    ListNode* B;
    ListNode* ans = nullptr;
    ListNode* tail = nullptr;
    
    
    while (A && A->next) {
        B = A->next;
        A->next = nullptr;
        ListNode* temp = A;
        A = B->next;
        B->next = temp;
        
        if (!ans) {
            ans = B;
            tail = temp;
        } else {
            tail->next = B;
            tail = temp;
        }
        
        
    }
    
    if (A) {
        tail->next = A;
    }
    
    return ans;
}
