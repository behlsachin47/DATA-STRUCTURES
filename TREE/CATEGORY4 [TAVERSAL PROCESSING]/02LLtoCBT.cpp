
void convert(Node *head, TreeNode *&root) {
    if (head == nullptr)
    {
        root = nullptr;
        return;
    }

    std::queue<TreeNode*> q;
    root = new TreeNode(head->data);
    head = head->next;
    q.push(root);

    while (!q.empty() && head) {
        TreeNode* curr = q.front();
        q.pop();
        TreeNode* currLeft = new TreeNode(head->data);
        curr->left = currLeft;
        q.push(currLeft);

        head = head->next;
        
        if (head) {
            TreeNode* currRight = new TreeNode(head->data);
            curr->right = currRight;
            q.push(currRight);
            head = head->next;
        }
    }
    
}