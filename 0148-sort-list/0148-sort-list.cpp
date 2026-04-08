/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Base case: If the list is empty or has only 1 node, it's already sorted.
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 1. Find the middle of the list
        ListNode* mid = getMid(head);
        
        // 2. Split the list into two halves
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr; // Sever the link to break it into two independent lists

        // 3. Recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        // 4. Merge the sorted halves
        return merge(left, right);
    }

private:
    // Helper function to find the middle using Fast & Slow pointers
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        // Start fast one step ahead so we get the *first* middle node in an even-length list
        ListNode* fast = head->next; 
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Helper function to merge two sorted linked lists in O(1) space
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0); // Dummy node to easily build the new list
        ListNode* tail = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next; // Move the tail forward
        }

        // If one of the lists is not empty, append the rest of it
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        return dummy.next;
    }
};