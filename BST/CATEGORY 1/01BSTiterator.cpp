#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int data): data(data) {
        right = nullptr;
        left = nullptr;
    }
};

class BST {
    Node* root;
    std::stack<Node*>* st;

public:
    BST():root(nullptr), st(nullptr) {};

    void BFS() {
        if (root == nullptr)
            return;

        Node* iter = root;
        std::queue<Node*>* q = new std::queue<Node*>;
        q->push(root);

        while (!q->empty()) {
            Node* curr = q->front();
            q->pop();
            std::cout << curr->data << " ";
            if (curr->left) {
                q->push(curr->left);
            }

            if (curr->right) {
                q->push(curr->right);
            }
        }
        std::cout << std::endl;
        delete q;
    }
    void push(int data) {
        Node* iter = root;
        Node* pIter = nullptr;

        while (iter) {
            pIter = iter;
            if (iter->data == data) 
                return;
            else if (iter->data > data) {
                iter = iter->left;
            } else {
                iter = iter->right;
            }
        }

        //check if pIter == nullptr; this means root is null
        if (pIter == nullptr) {
            root = new Node(data);
        } else {
            if (pIter->data > data) {
                pIter->left = new Node(data);
            } else if (pIter->data < data) {
                pIter->right = new Node(data);
            }
        }
    }

    int begin() {
        if (st != nullptr) {
            delete st;
        }
        st = new stack<Node*>;
        //maintain the top of stack as the lowest element always
        Node* curr = root;
        while (curr) {
            st->push(curr);
            curr = curr->left;
        }
        if (st->empty())
            return -1;
        else 
            return st->top()->data;
    }

    int next() {
        if (st == nullptr || st->empty()) {
            std::cerr << "begin not called or stack empty";
            return -1;
        }

        Node* curr = st->top()->right;
        st->pop();

        while(curr) {
            st->push(curr);
            curr = curr->left;
        }
        return st->top()->data;
    }

    bool isEnd() {
        if (st->empty())
            return true;
        return false;
    }


};

int main() {
    BST t;
    t.push(7);
    t.push(6);
    t.push(8);
    t.push(5);
    t.push(6.5);
    t.push(7.5);
    t.push(10);
    t.push(5.5);
    t.push(5.2);
    t.push(5.1);

    t.BFS();

    t.begin();
    while (!t.isEnd()) {
        std::cout << t.next() << endl;
    }

    std::cout << "o";

}