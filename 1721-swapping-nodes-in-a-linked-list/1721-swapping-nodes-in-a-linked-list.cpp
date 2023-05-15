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
    ListNode* swapNodes(ListNode* head, int k) {
    
      
        ListNode * front=head;
        
        while(--k)
        {
            front=front->next;
        }
        ListNode*first=front;
        ListNode*back=head;
        
        while(front->next!=NULL)
        {

            back=back->next;
            front=front->next;
        }
        swap(first->val,back->val);
        return head;

    }
};