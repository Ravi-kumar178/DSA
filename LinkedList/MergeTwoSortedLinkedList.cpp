/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node* temp1 = head1;
        Node* temp2 = head2;
        Node* tail = NULL;
        Node* head = NULL;
        
        while((temp1 != NULL)&&(temp2 != NULL)){
            if(temp1->data > temp2->data){
                Node* newNode = new Node(temp2->data);
                if(head == NULL){
                    head = newNode;
                    tail = newNode;
                }
                else{
                    tail->next = newNode;
                    tail = newNode;
                }
                temp2 = temp2->next;
            }
            else{
                Node* newNode = new Node(temp1->data);
                if(head == NULL){
                    head = newNode;
                    tail = newNode;
                }
                else{
                    tail->next = newNode;
                    tail = newNode;
                }
                temp1 = temp1->next; 
            }
        }
        
        while(temp1 != NULL){
                Node* newNode = new Node(temp1->data);
                if(head == NULL){
                    head = newNode;
                    tail = newNode;
                }
                else{
                    tail->next = newNode;
                    tail = newNode;
                }
                temp1 = temp1->next;
        }
        while(temp2 != NULL){
                Node* newNode = new Node(temp2->data);
                if(head == NULL){
                    head = newNode;
                    tail = newNode;
                }
                else{
                    tail->next = newNode;
                    tail = newNode;
                }
                temp2 = temp2->next;
        }
        return head;
    }
};