/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverseLL(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = head->next;
    
    while (curr) {
        curr->next = prev;
        prev = curr;
        curr = next;
        if (next)
            next = next->next;
        
    }
    
    return prev;
}

ListNode* Solution::reorderList(ListNode* A) {
    if (A == nullptr || A->next == nullptr || A->next->next == nullptr)
        return A;
    //get length and store the second half in a different linked List
    ListNode* slow = A;
    ListNode* fast = A;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;
    }
    ListNode* middle = slow;
    
    
    ListNode* head1 = A;
    ListNode* head2 = middle->next;
    middle->next = nullptr;
    head2 = reverseLL(head2);
    
    //std::cout << "doine" << std::endl;
    ListNode* head = nullptr;
    ListNode* iter = nullptr;
    
    while (head1 && head2) {
        ListNode* temp = head1->next;
        if (head == nullptr) {
            iter = head1;
            head = head1;
        } else {
            iter->next = head1;
            iter = iter->next;
        }
        
        iter->next = head2;
        iter = iter->next;
        
        head1 = temp;
        head2 = head2->next;
    }
    
    if (head1) {
        iter->next = head1;
    }
    
    return head;
    
    
}
