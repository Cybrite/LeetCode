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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* pmid = slow;
        ListNode* pcur = slow->next;
        while(pcur->next != NULL){
            ListNode* cur = pcur->next;
            pcur->next = cur->next;
            cur->next = pmid->next;
            pmid->next = cur;
        }

        slow = head;
        fast = pmid->next;

        while(slow != pmid){
            pmid->next = fast->next;
            fast->next = slow->next;
            slow->next = fast;
            slow = fast->next;
            fast = pmid->next;
        }
    }
};