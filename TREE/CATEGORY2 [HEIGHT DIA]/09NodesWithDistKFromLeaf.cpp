
void printKDistantfromLeaf(Node* node, int k, std::vector<int>& list, 
    std::vector<int>& res, vector<>) {
    if (node == nullptr) {
        return;
    }
    list.push_back(node);
    
    //check if this node is a leaf node
    if (node->left == nullptr && node->right == nullptr) {
        //check if there is a node with distance k from this node
        int n = list.size();
        if (n > k) {
            res.push_back(list[n-k-1]);
        }        
    } else {
        //go left
        printKDistantfromLeaf(node->left, k, list, res);
        //go right
        printKDistantfromLeaf(node->right, k, list, res);
    }
    
    list.pop_back();
}
int printKDistantfromLeaf(Node* node, int k)
{
    std::vector<Node*> list;
    std::unordered_set<Node*> res;
    printKDistantfromLeaf(node, k, list, res);
    return res.size();
}