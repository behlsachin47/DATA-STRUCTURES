/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverseList(ListNode* head) {
    if (head->next == nullptr) {
        return head;
    }
    
    ListNode* answer = reverseList(head->next);
    ListNode* tail = head->next;
    head->next = nullptr;
    tail->next = head;
    
    return answer;
}


int Solution::lPalin(ListNode* A) {
    if (A == nullptr || A->next == nullptr)
        return 1; 
    ListNode* slow = A;
    ListNode* fast = A->next;
    
    while (fast && fast->next) {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    }
    
    ListNode* head2 = slow->next;
    slow->next = nullptr;
    head2 = reverseList(head2);
    
    while (A && head2) {
        if (A->val != head2->val)
            return 0;
            
        A = A->next;
        head2 = head2->next;
    }
    
    return 1;
    
    
}
