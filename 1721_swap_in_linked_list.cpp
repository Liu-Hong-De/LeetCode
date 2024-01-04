/* You are given the head of a linked list, and an integer k.
Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed). */

// Difficulty: Medium
// Runtime: 808 ms, faster than 65.22% of C++ online submissions for Swapping Nodes in a Linked List.
// Memory Usage: 180.1 MB, less than 89.18% of C++ online submissions for Swapping Nodes in a Linked List.


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
	// calculate the length of the linked list
    int len(ListNode* head) {
        int count = 0;
        while(head) {
            count++;
            head = head->next;
        }
        return count;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* num1;
        int list_len = len(head);
        int count = 0;
        
        // ensure the position of k must close to head
        if(list_len-k+1 < k)
            k = list_len-k+1;

        while(temp) {
            count++;
            // the first swap number
            if(count == k) {
                num1 = temp;
            }
            
            // the second swap number
            if(count == list_len-k+1) {
                int num2 = temp->val;
                temp->val = num1->val;
                num1->val = num2;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};
