/* Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists. */ 

// Difficulty: Easy
// Runtime: 8 ms, faster than 82.10% of C++ online submissions for Merge Two Sorted Lists.
// Memory Usage: 14.7 MB, less than 97.74% of C++ online submissions for Merge Two Sorted Lists.

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        
        while(l1 != 0 && l2 != 0) {
            if(l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            }
            else {
                temp->next = l2;
                l2 = l2->next;
            }
            
            temp = temp->next;
        }
        
        if(l1 == 0) {
            temp->next = l2;
        }
        else if(l2 == 0) {
            temp->next = l1;
        }
        
        return ans->next;
    }
};
