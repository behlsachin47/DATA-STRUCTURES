/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/




class Solution {
public:
    void print(Node* root) {
        if (root == nullptr)
            return;
        std::cout << root->val << " ";
        root = root->right;
        print(root);
    }    
    
    void printRev(Node* root) {
        if (root == nullptr)
            return;
        std::cout << root->val << " ";
        root = root->left;
        printRev(root);
    }
    void bToDLL(Node* root, Node** head_ref, Node** tail_ref) {
    if (root == nullptr) {
        return;
    }
    Node* head_ref_left = nullptr;
    Node* tail_ref_left = nullptr;
    Node* head_ref_right = nullptr;
    Node* tail_ref_right = nullptr;

    bToDLL(root->left, &head_ref_left, &tail_ref_left);
    bToDLL(root->right, &head_ref_right, &tail_ref_right);

    Node* currNode = new Node(root->val);
    if (head_ref_left == nullptr) {
       if (head_ref_right != nullptr) {
           currNode->right = head_ref_right;
           //reverse link
           (head_ref_right)->left = currNode;

           *tail_ref = tail_ref_right;

       } else {
           *tail_ref = currNode;
       }
       
        *head_ref = currNode;

    } else {
        currNode->left = tail_ref_left;
        (tail_ref_left)->right = currNode;

        if (head_ref_right != nullptr) {
            currNode->right = head_ref_right;
            (head_ref_right)->left = currNode;

            
            *head_ref = head_ref_left;
            *tail_ref = tail_ref_right;
        } else {
            *head_ref = head_ref_left;
            *tail_ref = currNode;
        }

    }
        
    std::cout << root->val << std::endl;
    if (head_ref_left) 
        std::cout << head_ref_left->val << std::endl;
    else
        std::cout << "nullptr\n";
    
        
    if (tail_ref_left) 
        std::cout << tail_ref_left->val << std::endl;
    else
        std::cout << "nullptr\n";
    
        
    if (head_ref_right) 
        std::cout << head_ref_right->val << std::endl;
    else
        std::cout << "nullptr\n";
    
        
    if (tail_ref_right) 
        std::cout << tail_ref_right->val << std::endl;
    else
        std::cout << "nullptr\n";
    
        
}


    Node* treeToDoublyList(Node* root) {
        Node* tail_ref = nullptr;
        Node* head_ref = nullptr;
        bToDLL(root, &head_ref, &tail_ref);
        print(head_ref);
        printRev(tail_ref);
        return head_ref;
    }
};