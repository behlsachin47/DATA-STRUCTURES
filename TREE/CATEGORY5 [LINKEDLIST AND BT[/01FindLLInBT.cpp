/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool isSubPathU(TreeNode* root, std::vector<int>& arr, std::vector<int>& lps, int index) {
    if (index == arr.size())
        return 1;
    else if (root == nullptr)
        return 0;
   // std::cout << index << std::endl;
    if (root->val == arr[index]) {
        return isSubPathU(root->left, arr, lps, index+1) 
                || isSubPathU(root->right, arr, lps, index+1);
    } else {
        //mismatch happens; now choose the correct index
        if(index == 0) {
            return isSubPathU(root->left, arr, lps, index) || 
                isSubPathU(root->right, arr, lps, index);
        } else {
            index = lps[index-1];
            return isSubPathU(root, arr, lps, index);
        }
    }
}
int getListSize(ListNode* head) {
    if (!head)
        return 0;
    int size = 0;
    while (head)
    {
        head = head->next;
        size++;
    }
    return size;
}
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head && !root)
            return 1;
        else if (!head || !root)
            return 0;
        
        //find thre prefix is suffix array in the linked list
        int size = getListSize(head);
        std::vector<int> lps (size, 0);
        std::vector<int> arr (size, 0);
        ListNode* iter = head;

        for (int i = 0; iter != nullptr; i++) {
            arr[i] = iter->val;
            iter = iter->next;
        }

        lps.push_back(0);
        int j = 0;
        for (int i = 1; i < arr.size(); ) {
            if (arr[i] == arr[j]) {
                j++;
                lps[i] = j;
                i++;
            } else if (j == 0) {
                lps[i] = 0;
                i++;
            } else {
                j = lps[j-1];
            }
        }

        return isSubPathU(root, arr, lps, 0);
    }
};