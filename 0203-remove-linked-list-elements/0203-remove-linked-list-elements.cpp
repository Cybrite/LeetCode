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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = new ListNode(0);
        temp -> next = head;

        ListNode* prev = temp;
        ListNode* curr = head;

        while(curr){
            if(curr->val == val){
                prev->next = curr->next; // unlinking
                delete curr; // deletion
                curr = prev->next; // move fr
            }else{
                prev = curr;
                curr = curr->next;
            }
        }

        ListNode* newHead = temp->next;
        delete temp;
        return newHead;
    }
};