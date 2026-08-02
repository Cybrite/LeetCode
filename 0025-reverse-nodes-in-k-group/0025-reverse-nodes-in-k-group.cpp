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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;

        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while(cnt >= k){
            ListNode* curr = prev->next;

            for(int i=1; i<k; i++){
                ListNode* dum = curr->next;
                curr->next = dum->next;
                dum->next = prev->next;
                prev->next = dum;
            }

            prev = curr;
            cnt -= k;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};