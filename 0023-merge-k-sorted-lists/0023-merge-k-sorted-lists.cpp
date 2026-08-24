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
    struct compareNode{
        bool operator()(ListNode* const& p1, ListNode* const& p2){
            return p1->val > p2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compareNode> pq;

        for(ListNode* list : lists){
            if(list){
                pq.push(list);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();

            tail->next = temp;
            tail = tail->next;

            if(temp->next){
                pq.push(temp->next);
            }
        }

        return dummy.next;
    }
};