/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLL(ListNode* head1, ListNode* head2) {
        if (head1 == nullptr && head2 == nullptr)
            return nullptr;
        else if (head1 == nullptr) {
            return head2;
        } else if (head2 == nullptr) {
            return head1;
        }
        
        
        ListNode* head = nullptr;
        ListNode* iter = nullptr;
        
        while (head1 && head2) {
            if (head1->val >= head2->val) {
                if (head == nullptr) {
                    head = head2;
                    iter = head;
                } else {
                    iter->next = head2;
                    iter = head2;
                }
                
                head2 = head2->next;
            } else if (head2->val > head1->val) {
                if (head == nullptr) {
                    head = head1;
                    iter = head;
                } else {
                    iter->next = head1;
                    iter = head1;
                }
                head1 = head1->next;
            }
            
            
        }
        
        if (head1) {
            iter->next = head1;
        }
        
        if (head2) {
            iter->next = head2;
        }
        
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) {
            return nullptr;
        }
        int limit = pow(2, log2(n) + 1);
        for (int i = 2; i < limit ; i*=2) {
            for (int j = 0; j < n; j += i) {
                //merge two linked list j and j+i-1
                ListNode* head1 = lists[j];
                ListNode* head2 = nullptr;
                if (j + i/2 < n) {
                    head2 = lists[j + i/2];
                }
                
                lists[j] = mergeTwoLL(head1, head2);
                
            }
            //break;
        }
        
        return lists[0];
    }
};





//////////////////////////PRIORITY QUEUE BASED o(K) SPACE

class compareClass {
public:
  bool operator() (ListNode* n1, ListNode* n2) {
      return n1->val > n2->val;
  }
};

class Solution {
public:
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, compareClass> pq;
        int k = lists.size();
        for (int i = 0; i < k; i++) {
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }
        
        ListNode* head = nullptr;
        ListNode* iter = nullptr;
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            
            if (head == nullptr) {
                head = node;
                iter = node;
            } else {
                iter->next = node;
                iter = iter->next;
            }
            
            if (node->next) {
                pq.push(node->next);
            }
        }
        
        return head;
        
    }
};