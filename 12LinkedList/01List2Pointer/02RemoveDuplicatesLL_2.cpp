/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if (A == nullptr || A->next == nullptr)
        return A;
    
    ListNode* head = nullptr;
    ListNode* iter1 = A;
    ListNode* iter2 = nullptr;
    
    while (iter1) {
        int val = iter1->val;
        //std::cout << val << std::endl;
        ListNode* temp = iter1->next;
        if (temp && temp->val == val) {
        
            //delete all this
            ListNode* pTemp = iter1;
            while (temp && temp->val == val) {
                delete pTemp;
                pTemp = temp;
                temp = temp->next;
            }
            
            delete pTemp;
            iter1 = temp;
        } else {
            if (!head) {
                head = iter1;
                iter2 = iter1;
            } else {
                iter2->next = iter1;
                iter2 = iter2->next;
            }
            iter1 = iter1->next; 
            
        }
        
    }
    if (iter2)
    iter2->next = nullptr;
    
    return head;
}
