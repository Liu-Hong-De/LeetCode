/* Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list. Return the linked list sorted as well. */

// Runtime: 4 ms, faster than 94.36% of C++ online submissions for Remove Duplicates from Sorted List II.
// Memory Usage: 11.2 MB, less than 20.14% of C++ online submissions for Remove Duplicates from Sorted List II.

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = new ListNode(-101);
        prev->next = head;
        ListNode* cur = head;
        ListNode* next = prev;
        
        while(cur) {
            if(cur->next && cur->val == cur->next->val) {
                while(cur->next && cur->val == cur->next->val) {
                    cur = cur->next;
                }
                next->next = cur->next;
            }
            else {
                next = next->next;
            }
            cur = cur->next;
        }
        return prev->next;
    }
};
