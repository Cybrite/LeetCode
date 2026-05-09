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
        if(head == NULL) return head;
        ListNode* temp = head;

        vector<int> nums;
        while(temp != NULL){
            nums.push_back(temp->val);
            temp = temp->next;
        }
        int n = nums.size();
        swap(nums[k-1], nums[n-k]);

        temp = head;
        for(int i=0; i<n; i++){
            temp->val = nums[i];
            temp = temp->next;
        }

        return head;
    }
};