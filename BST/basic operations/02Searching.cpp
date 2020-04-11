bool search(Node* root, int x)
{
    if (root == nullptr)
        return 0;
    if (root->data == x) 
        return 1;
    else if (root->data > x) 
        return search(root->left, x);
    else 
        return search(root->right, x);
    //Your code here
}

//MIN VALUE IN A BT
int minValue(Node* root)
{
    if (root == nullptr)
        return -1;
    if (root->left == nullptr)
        return root->data;
    else 
        return minValue(root->left);
    // Code here
}
