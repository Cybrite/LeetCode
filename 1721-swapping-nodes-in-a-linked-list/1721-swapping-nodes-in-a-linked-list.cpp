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
        ListNode *left = head, *right = head, *curr = head;

        for(int i=1; i<k; i++){
            curr = curr->next;
        }
        left = curr;

        ListNode* ex = curr;
        while(ex->next){
            ex = ex->next;
            right = right->next;
        }

        swap(left->val, right->val);

        return head;
    }
};