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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move fast pointer n steps ahead
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        
        // Move both fast and slow pointers until fast reaches the end
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Skip the nth node
        ListNode* nodeToRemove = slow->next;
        slow->next = slow->next->next;
        
        // Delete the node to prevent memory leak (optional, depends on requirements)
        delete nodeToRemove;
        
        // Return the modified list, starting from the original head
        ListNode* newHead = dummy->next;
        delete dummy; // Free the dummy node
        return newHead;
    }
};