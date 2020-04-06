/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    void serialize(TreeNode* root, ostringstream& res) {
        if (root == nullptr)
        {
            res << "# " ;
            return;
        }
        res << std::to_string(root->val) << " ";
        serialize(root->left, res);
        serialize(root->right, res);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        ostringstream os;
        serialize(root, os);
        return os.str();
    }
    

    
    TreeNode* deserialize(istringstream& is) {
        string str;
        is >> str;
        if (str == "#") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(str));
        root->left = deserialize(is);
        root->right = deserialize(is);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return deserialize(is);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    void serialize(TreeNode* root, string& res) {
        if (root == nullptr)
        {
            res += 'N';
            return;
        }
        res += std::to_string(abs(root->val));
        if (root->val < 0)
            res += 'n';
        else
            res += 'p';
        serialize(root->left, res);
        serialize(root->right, res);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serialize(root, res);
        return res;
    }
    
    int getVal(const string& data, int& index) {
        int ans = 0;
        while (index <= data.size() && data[index] != 'p' && data[index] != 'n') {
            ans = ans*10 + (data[index] - '0');
            index++;
        }
        if (data[index] == 'n')
        return ans*-1;
        else
        return ans;
    }
    
    void deserialize(const string& data, int& index, TreeNode*& root) {
        if (index >= data.size())
            return;
        
        if (data[index] == 'N') {
            
            return;
        }
        
        
        int val = getVal(data, index);
        
        //std::cout << val << std::endl;
        root = new TreeNode(val);
        index++;
        deserialize(data, index, root->left);
        index++;
        deserialize(data, index, root->right);
        
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        TreeNode* root = nullptr;
        int ind = 0;
        deserialize(data, ind, root);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));