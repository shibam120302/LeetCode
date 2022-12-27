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
        
        if(head==NULL)return NULL;
        if(head->next==NULL)return NULL;
        ListNode* temp=head;
        ListNode* temp2=head;
        while(n--){
            temp=temp->next;
        }
        while(temp!=NULL && temp->next!=NULL){
            temp=temp->next;
            temp2=temp2->next;
        }
        if(temp2==head && temp==NULL){
            head=head->next;
        }else{
            temp2->next=temp2->next->next;
        }
        return head;
        
    }
};
