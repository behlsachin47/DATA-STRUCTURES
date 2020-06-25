/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) ;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
void attachToList(ListNode* &head, ListNode* &iter, ListNode* &node) {
    if (head == nullptr) {
        head = node;
        iter = node;
    } else {
        iter->next = node;
        iter = node;
    }
}
ListNode* Solution::partition(ListNode* A, int x) {
    ListNode* head1 = nullptr;
    ListNode* head2 = nullptr;
    
    ListNode* iter1 = nullptr;
    ListNode* iter2 = nullptr;
    
    
    while (A) {
        if (A->val < x) {
            attachToList(head1, iter1, A);
        } else {
            attachToList(head2, iter2, A);
        }
        
        A = A->next;
    }
    
    if (!head1 && !head2) {
        return nullptr;
    } else if (!head1) {
        return head2;
    } else if (!head2) {
        return head1;
    } else {
        iter1->next = head2;
        iter2->next = nullptr;
        return head1;
    }
}
