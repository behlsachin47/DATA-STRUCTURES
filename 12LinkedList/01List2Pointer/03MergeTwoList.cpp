/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* head = nullptr;
    ListNode* iter = nullptr;
    if (!A && !B)
        return nullptr;
    else if (!A)
        return B;
    else if (!B)
        return A;
        
        
    while (A && B) {
        if (A->val > B->val) {
            if (!head) {
                head = B;
                iter = B;
            } else {
                iter->next = B;
                iter = B;
            }
            B = B->next;
        } else {
            if (!head) {
                head = A;
                iter = A;
            } else {
                iter->next = A;
                iter = A;
            }
            A = A->next;
        }
    }
    
    if (A) {
        iter->next = A;
    } else {
        iter->next = B;
    }
    
    return head;
}
