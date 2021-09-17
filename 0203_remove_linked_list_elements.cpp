/* Given the head of a linked list and an integer val,
remove all the nodes of the linked list that has Node.val == val, and return the new head. */

// Runtime: 20 ms, faster than 83.09% of C++ online submissions for Remove Linked List Elements.
// Memory Usage: 15 MB, less than 78.95% of C++ online submissions for Remove Linked List Elements.

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
    ListNode* removeElements(ListNode* head, int val) {
        ans = head;
        while(ans && ans->val == val) {
            ans = ans->next;
        }
        head = ans;
        while(ans) {
            while(ans->next && ans->next->val == val) {
                ans->next = ans->next->next;
            }
            ans = ans->next;
        }
        return head;
    }
    
private:
    ListNode* ans;
};
