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
    
    ListNode *reverse(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *head2 = reverse(head->next);
        head->next->next = head;
        return head2;
    }

    int getCount(ListNode *head) {
        int count = 0;
        while(head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }

    int pairSum(ListNode* head) {
        int count = getCount(head);
        ListNode *curr = head;
        ListNode *prev = NULL;
        for(int i = 0; i < count / 2; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        ListNode *head2 = reverse(curr);
        int ans = 0;
        for(int i = 0; i < (count / 2); i++) {
            ans = max(ans, head->val + head2->val);
            head = head->next;
            head2 = head2->next;
        }
        return ans;
    }
};