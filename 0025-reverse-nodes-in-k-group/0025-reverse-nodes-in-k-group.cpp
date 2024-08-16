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
    ListNode* reverseKGroup(ListNode* head, int k) {
          ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        // Pointers for previous group and current
        ListNode *prevGroupEnd = dummy;
        ListNode *curr = head;
        
        while (curr) {
            // Check if there are at least k nodes left in the list
            ListNode *groupStart = curr;
            int count = 0;
            while (curr && count < k) {
                curr = curr->next;
                count++;
            }
            
            if (count == k) {
                // Reverse the k nodes
                ListNode *reversedList = reverseList(groupStart, k);
                
                // Connect the previous group's end to the reversed list
                prevGroupEnd->next = reversedList;
                
                // Move prevGroupEnd to the end of the reversed list
                prevGroupEnd = groupStart;
            } else {
                // Less than k nodes, so connect directly and break
                prevGroupEnd->next = groupStart;
                break;
            }
        }
        
        return dummy->next;
    }
    
    // Helper function to reverse a linked list of size k
    ListNode* reverseList(ListNode* head, int k) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        
        while (k > 0) {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            k--;
        }
        
        return prev;
    }
};