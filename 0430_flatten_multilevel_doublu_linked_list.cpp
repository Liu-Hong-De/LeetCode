/* You are given a doubly linked list which in addition to the next and previous pointers, 
it could have a child pointer, which may or may not point to a separate doubly linked list. 
These child lists may have one or more children of their own, and so on, 
to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list. */

// Difficulty: Medium
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Flatten a Multilevel Doubly Linked List.
// Memory Usage: 7.4 MB, less than 62.64% of C++ online submissions for Flatten a Multilevel Doubly Linked List.


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head;
        Node* nxt = NULL;
        while(temp) {
            if(temp->child) {
                temp->child = flatten(temp->child);
                nxt = temp->next;
                temp->next = temp->child;
                temp->next->prev = temp;
                temp->child = NULL;
            }
            if(!temp->next && nxt) {
                temp->next = nxt;
                nxt->prev = temp;
                nxt = NULL;
            }
            temp = temp->next;
        }
        return head;
    }
};
