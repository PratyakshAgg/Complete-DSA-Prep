//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        while(curr){
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* new_head = reverse(head);
        Node* current = new_head, *prev = NULL, *current1 = new_head;
        int carry = 0;
        while(current != NULL){
            int sum = 0;
            if(!prev) sum = current->data + 1;
            else sum = current->data + carry;
            
            carry = sum/10;
            current->data = sum%10;
            prev = current;
            current = current->next;
        }
        
        if(carry == 1){
            Node* new_node = new Node(1);
            prev->next = new_node;
        }
        return reverse(current1);
    }
};