/* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself. */

// Difficulty: Medium
// Runtime: 20 ms, faster than 95.53% of C++ online submissions for Add Two Numbers.
// Memory Usage: 70.6 MB, less than 95.99% of C++ online submissions for Add Two Numbers.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = l1;
        ListNode* front = l1;
        bool carry = false;
        
//        相對應位置相加 
        while(l1->next != 0 && l2->next != 0) {
            l1->val += l2->val;
            l1 = l1->next;
            l2 = l2->next;
        } 
        l1->val += l2->val;
        
//        無相對應位置合併 
        if(l2->next != 0) {
            l1->next = l2->next;
        }
        
//        處理進位 
        while(front != 0) {
            if(carry) {
                front->val += 1;
                carry = false;
            }
            if(front->val > 9) {
                front->val -= 10;
                if(front->next == 0) {
                    front->next = new ListNode(1);
                }
                else {
                    carry = true;
                }
            }
            front = front->next;
        }
        return ans;
    }
};
