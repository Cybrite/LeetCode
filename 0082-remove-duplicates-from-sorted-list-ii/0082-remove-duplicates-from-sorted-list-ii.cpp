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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* temp = new ListNode(0);
        temp->next = head;

        ListNode* prev = temp;
        ListNode* curr = head;

        while(curr != NULL && curr->next != NULL){
            if(curr->val == curr->next->val){
                int dup = curr->val;

                while(curr != NULL && curr->val == dup){
                    curr = curr->next;
                }

                prev->next = curr;
            }else{
                prev = prev->next;
                curr = curr->next;
            }
        }

        ListNode* newHead = temp->next;
        delete temp;
        return newHead;
    }
};