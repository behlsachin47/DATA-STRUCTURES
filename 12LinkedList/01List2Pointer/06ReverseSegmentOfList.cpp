/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverseUtil(ListNode* node, int B, int C) {
    ListNode* pNode = nullptr;
    ListNode* cNode = node;
    ListNode* nNode = node->next;
    
    while (B <= C && cNode) {
        cNode->next = pNode;
        pNode = cNode;
        cNode = nNode;
        if (nNode)
            nNode = nNode->next;
        B++;
    }
    
    node->next = cNode;
    
    return pNode;
    
}
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    //reach to mth node first
    if (A == nullptr || A->next == nullptr)
        return A;
        
    ListNode* mNode = A;
    ListNode* pMNode = nullptr;
    
    for (int i = 0; i < B-1; i++) {
        pMNode = mNode;
        mNode = mNode->next;
    }
    
    if (mNode == nullptr)
        return A;
    else {
        if (pMNode) {
          pMNode->next = reverseUtil(mNode, B, C);
        } else {
            return reverseUtil(mNode, B, C);
        }
    }
    
    return A;
    
}
