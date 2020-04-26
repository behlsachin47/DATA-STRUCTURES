Node* insert(Node* node, int data)
{
    if (node == nullptr) {
        node = newNode(data);
    } else if (node->data > data) {
        node->left = insert(node->left, data);
    } else if (node->data < data) {
        node->right = insert(node->right, data);
    }
    return node;
    // Your code here
}