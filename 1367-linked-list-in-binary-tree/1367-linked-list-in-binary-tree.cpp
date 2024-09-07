class Solution {
public:
    // Helper function to check if the linked list starting from 'head' matches a path starting from 'root'
    bool checkPath(ListNode* head, TreeNode* root) {
        // Base cases
        if (head == nullptr) return true;  // Reached the end of the list, so it's a match
        if (root == nullptr) return false; // Reached a null node in the tree without matching all nodes

        // If current nodes match, check left and right children for next list node
        if (root->val == head->val) {
            return checkPath(head->next, root->left) || checkPath(head->next, root->right);
        }
        
        return false;  // Current node doesn't match
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) return false; // No tree nodes left to check
        
        // Check if the current tree node starts a valid path, or try the left and right subtrees
        return checkPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

