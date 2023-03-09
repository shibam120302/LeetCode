/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> visited;
        ListNode* cur = head;
        while(cur != NULL){
            if(visited.find(cur) != visited.end()){
                return cur;
            }else{
                visited.insert(cur);
            }
            cur = cur->next;
        }
        return NULL;
    }
};