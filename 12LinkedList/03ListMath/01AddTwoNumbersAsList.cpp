/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    if (!A && !B)
        return nullptr;
    else if (!A)
        return B;
    else if (!B)
        return A;
        
        
    ListNode* head = nullptr;
    ListNode* iter = nullptr;
    int carry = 0;
    while (A && B) {
        int val = A->val + B->val + carry;
        carry = val/10;
        val = val%10;
        
        ListNode* newNode = new ListNode(val);
        
        if (!head) {
            head = newNode;
            iter = newNode;
        } else {
            iter->next= newNode;
            iter = iter->next;
        }
        
        A = A->next;
        B = B->next;
    }
    
    while (A) {
        int val = A->val + carry;
carry = val/10;
        val = val%10;
        
        
        ListNode* newNode = new ListNode(val);
        iter->next = newNode;
        iter = iter->next;
        
        A = A->next;
    }
    
    while (B) {
        int val = B->val + carry;
 carry = val/10;
        val = val%10;
       
        
        ListNode* newNode = new ListNode(val);
        iter->next = newNode;
        iter = iter->next;
        
        B = B->next;
    }
    
    
    if (carry) {
        ListNode* newNode = new ListNode(carry);
        iter->next = newNode;
    }
    
    return head;
}
