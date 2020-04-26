struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data): data(data), left(nullptr), right(nullptr) {}
    Node(): data(0), left(nullptr), right(nullptr) {}
};

void LevelOrderTraversal(Node* root) {
    if (root == nullptr)
        return ;
    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        std::cout << curr->data << " ";

        if (curr->left)
            q.push(curr->left);
        
        if (curr->right)
            q.push(curr->right);

    }
}



void LevelOrderTraversalNewLine(Node* root) {
    if (root == nullptr)
        return ;
    std::queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        if (curr)
        std::cout << curr->data << " ";
        else {
            if (q.empty())
                continue;
            else {
                std::cout << std::endl;
                q.push(nullptr);
            }
        }
        if (curr->left)
            q.push(curr->left);
        
        if (curr->right)
            q.push(curr->right);

    }
}