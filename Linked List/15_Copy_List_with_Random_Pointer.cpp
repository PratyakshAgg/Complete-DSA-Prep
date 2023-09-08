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

        //Insert the new nodes in between the original linked list
        Node* curr = head;
        while(curr){
            Node* currNext = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = currNext;

            curr = currNext;
        }

        //Deep copy of random pointers
        curr = head;
        while(curr && curr->next){
            if(!curr->random){
                curr->next->random = NULL;
            }
            else{
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        //Separate the Linked Lists
        curr = head;
        Node* newHead = head->next;
        Node* newCurr = newHead;

        while(curr && newCurr){
            curr->next = curr->next == NULL ? NULL : curr->next->next;
            newCurr->next = newCurr->next == NULL ? NULL : newCurr->next->next;
            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
};