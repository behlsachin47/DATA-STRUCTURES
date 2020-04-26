struct Node {
    int data;
    Node* left;
    Node* right;
    int freq ;
    int countLeft;
    Node(int data): data(data) {
        left = nullptr;
        right = nullptr;
        countLeft = 0;
        freq = 1;
    }
    
    Node(): Node(0) {}
};

class BST {
    Node* root;
    const bool debug = 1; 
    
public:
    BST(): root(nullptr) {}
    int search(int num) {
        if (root == nullptr)
            return -1;
        int ans = 0;
        Node* iter = root;
        while (iter) {
            if (iter->data == num) {
                ans += iter->countLeft;
                iter->freq++;
                return ans;
            }
            else if (iter->data > num) {
                iter->countLeft++;
                iter = iter->left;
            }
            else {
                ans += iter->countLeft + iter->freq;
                
                iter = iter->right;
            }
        }
        return -1;
        
    }
    
  
    
    int InsertAndCountSmallerThan(int num) {
        //do inorder traversal or what ??
        if (root == nullptr) {
            root = new Node(num);
            return 0;
        }
        int ans = 0;
        Node* pIter = nullptr;
        Node* iter = root;
        while (iter) {
            pIter = iter;
            if (iter->data == num) {
                ans += iter->countLeft;
                iter->freq++;
                return ans;
            } else if (iter->data > num) {
                iter->countLeft ++;
                iter = iter->left;
            } else {
                ans += iter->countLeft + iter->freq;
                iter = iter->right;
            }
        }
        
        if (pIter->data > num) {
            pIter->left = new Node(num);    
        } else {
            pIter->right = new Node(num);
        }
        
        return ans;
        
    }
    
    void printStats() {
        if (root == nullptr) {
            return;
        }
        
        std::stack<Node*> s;
        Node* iter = root;
        while (iter || s.empty() == false) {
            while (iter) {
                s.push(iter);
                iter = iter->left;
            }
            
            while (!s.empty()) {
                Node* temp = s.top();
                std::cout << s.top()->data << " freq: " << s.top()->freq << 
                    " countLeft: " << s.top()->countLeft << std::endl;
                s.pop();
                
                if (temp->right)
                    iter = temp->right;
                
            }
        }
    }
    
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        std::vector<int> res;
        BST b;
        int count = 0;
        for (int i = nums.size()-1; i >= 0; i--) {
            res.push_back(b.InsertAndCountSmallerThan(nums[i]));
            /*count++;
            if (count == 24) {
                b.printStats();
                break;
            }*/
        }
        std::reverse(res.begin(), res.end());        
        return res;
    }
};



///O(N^2)
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        std::vector<int> res;
        int n = nums.size();
        std::multiset<int> m;
        for (int i = n-1; i >=0; i--) {
            m.insert(nums[i]);
            auto iter = m.lower_bound(nums[i]);
            res.push_back(std::distance(m.begin(), iter));
           // std::cout << "hhshs";
            
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};