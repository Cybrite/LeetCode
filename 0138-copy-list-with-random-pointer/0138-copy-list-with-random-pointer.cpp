/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;

        Node* temp = head;
        while(temp != NULL){
            Node* nxtO = temp->next;
            Node* clone = new Node(temp->val);
            temp->next = clone;
            clone->next = nxtO;
            temp = nxtO;
        }

        temp = head;
        while(temp != NULL){
            Node* clone = temp->next;

            if(temp->random != NULL){
                clone->random = temp->random->next;
            }

            temp = temp->next->next;
        }

        temp = head;
        Node* cloneHead = head->next;
        Node* cloneTemp = cloneHead;

        while(temp != NULL){
            temp->next = temp->next->next;

            if(cloneTemp->next != NULL){
                cloneTemp->next = cloneTemp->next->next;
            }

            temp = temp->next;
            cloneTemp = cloneTemp->next;
        }

        return cloneHead;
    }
};