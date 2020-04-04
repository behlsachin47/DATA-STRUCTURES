
Node *createTree(int parent[], int n)
{
    if (n == 0)
        return nullptr;
    //total 0 - n-1 nodes
    //map between values and nodes addresses
    std::unordered_map<int, Node*> map1;
    int rootVal = -1;
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node(i);
        map1.insert({i, newNode});
    }

    for (int i = 0; i < n; i++) {
        int par = parent[i];
        if(par == -1) {
            rootVal = i;
            continue;
        }
        int child = i;
        if (map1[par]->left == nullptr) {
            map1[par]->left = map1[child];
        } else {
            map1[par]->right = map1[child];
        }
    }

    return map1[rootVal];
}