// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Nth Node From End of List.
// Memory Usage: 10.7 MB, less than 73.51% of C++ online submissions for Remove Nth Node From End of List.

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
        ListNode* temp = head;
        int l = length(temp)-1;
//        �h���ߤ@��node 
        if(l == 0) {
            head = NULL;
        }
//        �h���Ĥ@��node 
        else if(l+1 == n) {
            head = head->next;
        }
        else {
//        	���n�Q�h����node��m 
            while(l > n) {
                temp = temp->next;
                l--;
            }
//            ��n�Q�h����node���̫�@�ӮɡA�O�䬰null 
            if(n == 1) {
                temp->next = NULL;
            }
            else {
                temp->next = temp->next->next;
            }
        }
        return head;
    }
    
//    �p��Llinked list���� 
    int length(ListNode* head) {
        int count = 0;
        while(head) {
            count++;
            head = head->next;
        }
        return count;
    }
};
