/* Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. 
This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, 
and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts. */


// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Split Linked List in Parts.
// Memory Usage: 8.8 MB, less than 91.53% of C++ online submissions for Split Linked List in Parts.


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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* temp = head;
        int l = length(head);	// linked list size
        int quotient = l / k;	// basic number of nodes in a part
        int remainder = l % k;	// additional number of nodes in front parts
        int count = 0;
        
        while(k > 0) {
            while(quotient > count+1) {
                temp = temp->next;
                count++;
            }
            
            if(remainder > 0) {
                if(quotient > 0) {
                    temp = temp->next;
                }
                remainder--;
            }
            
            if(temp && temp->next) {
            	if(temp->next) {
            		ListNode* next_begin = temp->next;
	                temp->next = NULL;
	                ans.push_back(head);
	                head = next_begin;
	                temp = next_begin;
	                count = 0;
				}
                else{
	                ans.push_back(head);
	                temp = NULL;
				}
            }
            else{
                ans.push_back(NULL);
            }
            
            k--;
        }
        return ans;
    }
    
    int length(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        
        while(temp) {
            count += 1;
            temp = temp->next;
        }
        return count;
    }
};
