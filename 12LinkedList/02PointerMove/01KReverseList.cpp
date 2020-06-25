/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    //REACH TO THE K TH NODE AND CALL THIS FUNCTION RECURSIVELY
    if (A == nullptr)
        return A;
    
    ListNode* A_prime = A;
    for (int i = 1; i <= B && A_prime; i++) 
        A_prime = A_prime->next;
        
    ListNode* smallAns = reverseList(A_prime, B);
    //now reverse this subpart
    ListNode* prevNode = nullptr;
    ListNode* currNode = A;
    ListNode* nextNode = A->next;
    
    while (currNode && B) {
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
        if (nextNode)
            nextNode = nextNode->next;
        B--;
    }
    
    A->next = smallAns;
    return prevNode;
}
