/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::sortList(ListNode* A) {
    
    //lets try merge sort here :)
    if (A == nullptr || A->next == nullptr)
        return A;
    
    //divide
    ListNode* slow = A;
    ListNode* fast = A->next;
    
    while (fast && fast->next) {
        fast = fast->next;
        fast = fast->next;        
        slow = slow->next;
    }
    
    ListNode* list2 = slow->next;
    slow->next = nullptr;
    list2 = sortList(list2);
    A = sortList(A);
    
    //merge step
    
    ListNode* head = nullptr;
    ListNode* iter = nullptr;
    
    while (list2 && A) {
        if (A->val >= list2->val) {
            if (!head) {
                head = list2;
                iter = list2;
            } else {
                iter->next = list2;
                iter = list2;
            }
            
            list2 = list2->next;
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
    
    if (list2) {
        iter->next = list2; 
    }
    
    if (A) {
        iter->next = A;
    }
    
    return head;
}
