void PreOrderTraversal(Node* root, vector<int>& res) {
    if (root == nullptr) {
        res.push_back(INT_MIN);
        return;
    }

    res.push_back(root->data);
    PreOrderTraversal(root->left, res);
    PreOrderTraversal(root->right, res);
}

bool debug = 0;
bool KMP(vector<int>& vec_main, vector<int>& vec_sub) {
    //first process the pattern to get lps array
    vector<int> lps (vec_sub.size(), 0);
    int j = 0;
    for (int i = 1; i < vec_sub.size(); ) {
        if (vec_sub[i] == vec_sub[j]) {
            lps[i] = lps[j] + 1;
            j++;
            i++;
        } else {
            if (j == 0) {
                lps[i] = 0;
                i++;
            } else {
                j = lps[j-1];
            }
        }
    }
    
    if (debug) {
        //lps array
        for (int i = 0; i < lps.size(); i++)
            std::cout << lps[i] << " ";
        std::cout << std::endl;
    }
    //return 0;
    //now pattern searching starts
    int ind1 = 0;
    int ind2 = 0;
    while (ind1 < vec_sub.size() && ind2 < vec_main.size()) {
        //std::cout << ind1 << " " << ind2 << std::endl;
        if (vec_main[ind2] == vec_sub[ind1]) {
            ind1++;
            ind2++;
        } else {
            if (ind1 == 0) {
                ind2++;
            } else {
                ind1 = lps[ind1-1];
            }
        }
    }

    if (ind1 == vec_sub.size())
        return true;
    return false;
}
bool isSubTree(Node* root, Node* sub) {
    vector<int> vec_main;
    vector<int> vec_sub;
    PreOrderTraversal(root, vec_main);
    PreOrderTraversal(sub, vec_sub);
    if (debug) {
        std::cout << "main vector \n";
        for (int i = 0; i < vec_main.size(); i++)
            std::cout << vec_main[i] << " ";
        std::cout << "\n sub vector\n";
        
        for (int i = 0; i < vec_sub.size(); i++) 
            std::cout << vec_sub[i] << " ";
        std::cout << "\n\n";
    }
    return KMP(vec_main, vec_sub);
    
}

