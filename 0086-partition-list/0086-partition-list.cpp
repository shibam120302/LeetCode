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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return head;
        
        ListNode* smallerHead=new ListNode(); //Head of the list with nodes <x
        ListNode* smallerTail=smallerHead; //Tail of the list with nodes <x
        
        ListNode* greaterHead=new ListNode();//Head of the list with nodes >=x
        ListNode* greaterTail=greaterHead; //Tail of the list with nodes >=x
        
        ListNode* curr = head;
        while (curr) {//partition into greater & smaller lists
            if (curr->val < x) {
                smallerTail->next = curr;
                smallerTail =smallerTail->next;
            } 
            else {
                greaterTail->next = curr;
                greaterTail=greaterTail->next;
            }
            curr = curr->next;
        }
        
        greaterTail->next = NULL; 
        smallerTail->next = greaterHead->next;//Connect the smaller and the greater lists
        
        head = smallerHead->next; //Update the head of the list
       
        return head;
    }
};