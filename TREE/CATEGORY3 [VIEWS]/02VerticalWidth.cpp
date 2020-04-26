void verticalWidth(Node* root, int& min, int& max, int cWidth) {
    if (root == nullptr)
        return;
    
    if (min > cWidth)
        min = cWidth;
    
    if (cWidth > max)
        max = cWidth;
    
    verticalWidth(root->left, min, max, cWidth-1);
    verticalWidth(root->right, min, max, cWidth+1);
}
int verticalWidth(Node* root)
{
    if (root == nullptr)
        return 0;
    int min = 0;
    int max = 0;
    
    verticalWidth(root, min, max, 0);
    return max-min+1;
    
    // Code here
}
