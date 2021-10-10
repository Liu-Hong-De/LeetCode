// Given the head of a linked list, rotate the list to the right by k places.

// Runtime: 4 ms, faster than 94.09% of C++ online submissions for Rotate List.
// Memory Usage: 11.7 MB, less than 88.37% of C++ online submissions for Rotate List.

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) {
            return head;
        }
        
        int l = length(head);
        if(k >= l) {
            k %= l;
        }
        
        if(k == 0) {
            return head;
        }
        
        ListNode* ans = head;
        ListNode* prev;
        while(ans->next) {
            prev = ans;
            ans = ans->next;
        }
        prev->next = NULL;
        ans->next = head;
        k--;
        if(k != 0) {
            ans = rotateRight(ans, k);
        }
        return ans;
    }
    
    int length(ListNode* head) {
        int count = 0;
        while(head) {
            count++;
            head = head->next;
        }
        return count;
    }
};
