
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        
        std::queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        Node* prev = nullptr;
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                if (!q.empty())
                {
                    prev = nullptr;
                    q.push(nullptr);
                }
                continue;
            }

            if (prev != nullptr)
                prev->next = curr;
            prev = curr;

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }
    }
};


///////////////////////SOLUTION2 //////////////////////

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;

        Node* curr = root;
        Node* nextLevelHead = nullptr;
        Node* nextLevelIter = nullptr;

        while (curr) {
            while(curr) {
                if (curr->left) {
                    if (nextLevelHead == nullptr) {
                        nextLevelHead = curr->left;
                        nextLevelIter = curr->left;
                    } else {
                        nextLevelIter->next = curr->left;
                        nextLevelIter = curr->left;
                    }
                }

                if (curr->right) {
                    if (nextLevelHead == nullptr) {
                        nextLevelHead = curr->right;
                        nextLevelIter = curr->right;
                    } else {
                        nextLevelIter->next = curr->right;
                        nextLevelIter = curr->right;
                    }
                }

                curr = curr->next;
            }
            curr = nextLevelHead;
            nextLevelHead = nullptr;
        }      
        return root;
    }
};