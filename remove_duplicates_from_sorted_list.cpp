// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well. 

// Runtime: 8 ms, faster than 86.95% of C++ online submissions for Remove Duplicates from Sorted List.
// Memory Usage: 11.6 MB, less than 75.48% of C++ online submissions for Remove Duplicates from Sorted List.

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
        ListNode* temp = head;
        while(temp) {
//        	若值和下一個值重複，則將連結連道下下個節點 
            while(temp->next && temp->val == temp->next->val) {
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
        return head;
    }
};
