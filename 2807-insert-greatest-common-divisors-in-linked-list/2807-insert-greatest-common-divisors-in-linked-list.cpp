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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
            if (!head || !head->next) {
            // If there's only one node or no node, return the original list
            return head;
        }
        
        ListNode* curr = head;
        
        while (curr && curr->next) {
            // Get the next node
            ListNode* nextNode = curr->next;
            
            // Calculate GCD of current and next node's values
            int gcdVal = gcd(curr->val, nextNode->val);
            
            // Create a new node with the GCD value
            ListNode* newNode = new ListNode(gcdVal);
            
            // Insert the new node between curr and nextNode
            curr->next = newNode;
            newNode->next = nextNode;
            
            // Move to the next pair of nodes
            curr = nextNode;
        }
        
        return head;
    }
};