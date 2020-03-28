void printSpiral(Node *root)
{
    if (root == nullptr)
        return;
    
    std::stack<Node*> s1;
    std::stack<Node*> s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty()) {
        if (s1.empty()) {
            //push the elements in s1 left; right
            while(!s2.empty()) {
                Node* curr = s2.top();
                s2.pop();

                std::cout << curr->data << " ";
                if (curr->left)
                    s1.push(curr->left);
                
                if (curr->right)
                    s1.push(curr->right);
            }
        } else {
            //push the elements in s1 left; right
            while(!s1.empty()) {
                Node* curr = s1.top();
                s1.pop();

                std::cout << curr->data << " ";
                if (curr->right)
                    s2.push(curr->right);
                
                if (curr->left)
                    s2.push(curr->left);
            }
        }
    }
}

