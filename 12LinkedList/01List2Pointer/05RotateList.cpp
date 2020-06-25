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
    ListNode* rotateRight(ListNode* head, int k);
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
int getLength(ListNode* head) {
    int len = 0;
    while (head) {
        head = head->next;
        len++;
    }
    return len;
}


ListNode* Solution::rotateRight(ListNode* A, int B) {
    if (A == nullptr || A->next == nullptr)
        return A;
    
    int len = getLength(A);
    //std::cout << len << std::endl;
    B = B % len;
    
    
    if (B == 0)
        return A;
        
    B = len - B ;
    ListNode* newHead = A;
    ListNode* pNewHead = nullptr;
    for (int i = 0; i < B; i++) {
        pNewHead = newHead;
        newHead = newHead->next;
    }
    //std::cout << newHead->val << std::endl;
    
    //CASE1: newHead == nullptr
        //never happens
    //CASE2: pNewHead == nullptr
        //B == 0
        
    pNewHead->next = nullptr;
    ListNode* tail = newHead;
    while (tail->next != nullptr)
        tail = tail->next;
    
    tail->next = A;
    
    return newHead;
}
