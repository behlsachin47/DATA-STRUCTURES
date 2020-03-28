int height(Node* node)
{
    if (node == nullptr)
        return 0;
    
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return 1 + std::max(leftHeight, rightHeight);
}

int diaHelper(Node* node, int& dia) {
    if (node == nullptr) {
        return 0;
    } 
    
    int h1 = diaHelper(node->left, dia);
    int h2 = diaHelper(node->right, dia);
    dia = std::max(dia, h1 + h2 + 1);
    return std::max(h1, h2) + 1;
}
int diameter(Node* node)
{
    int dia = 0;
    diaHelper(node, dia);
    return dia;
}


int isBalancedHelper(Node* root, bool& ans) {
    if (root == nullptr)
        return 0;
    
    int h1 = isBalancedHelper(root->left, ans);
    int h2 = isBalancedHelper(root->right, ans);
    if (ans && abs(h1-h2) <= 1)
    {
        return 1 + std::max(h1, h2);
    }
    
    ans = false;
    return -1;
    
    
}
bool isBalanced(Node *root)
{
    bool ans = true;
    isBalancedHelper(root, ans);
    return ans;
}
