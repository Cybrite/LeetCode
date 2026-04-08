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
    ListNode* sorted_insert(ListNode* newNode, ListNode* sorted){
        if(sorted == NULL || sorted->val >= newNode->val){
            newNode->next = sorted;
            sorted = newNode;
        }else{
            ListNode* curr = sorted;

            while(curr->next != NULL && curr->next->val < newNode->val){
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }

        return sorted;
    }
    
    ListNode* insertion_sort(ListNode* head){
        ListNode* sorted = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* next = curr->next;
            sorted = sorted_insert(curr,sorted);
            curr = next;
        }

        return sorted;
    }

    ListNode* insertionSortList(ListNode* head) {
        return insertion_sort(head);
    }
};