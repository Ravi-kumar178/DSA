#include<iostream>
using namespace std;

class Node{
    public:
     int data;
     Node* next;
     
    Node(){
        // cout<<"Inside Default Constructor"<<endl;
        this -> next = NULL;
    }
    
    Node(int data){
        // cout<<"Inside Parametarised Constructor"<<endl;
        this->data = data;
        this->next = NULL;
    }
};

//print linked list data
void printLinkedList(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

int countLenghtOfLinkedList(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}

//insertion at head
void insertionAtHead(Node* &head, Node* &tail ,int data){
    if(head == NULL){
        //create new Node
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        //create new Node
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

//insertion at tail
void insertionAtTail(Node* &head,Node* &tail, int data){
    //create new Node
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode = tail;
    }
    
}

//insertion at middle
void insertionAtMiddle(Node* &head, Node* &tail, int data, int position){
   int length = countLenghtOfLinkedList(head);
   if(position <= 1){
       //insert at head
       insertionAtHead(head,tail,data);
   }
   else if(position > length){
       //insert at tail
       insertionAtTail(head,tail,data);
   }
   else{
       //insert at middle
       
       //create a node 
       Node* newNode = new Node(data);
       //take curr pointer = head and prev = NULL, iterate untill position = 1;
       Node* curr = head;
       Node* prev = NULL;
       while(position != 1){
           prev = curr;
           curr = curr->next;
           position--;
       }
       //prev->next = newNode, newNode->next - curr
       prev->next = newNode;
       newNode->next = curr;
   }
}

int main(){
    // Node a;
    // Node* head = new Node();
    //create Node
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    Node* head = first;
    Node* tail = fifth;
    
    printLinkedList(head);
    
    //count the length of linked list
    int linkedListCount = countLenghtOfLinkedList(head);
    cout<<"Length of Linked list: "<<linkedListCount<<endl;
    
    //Insertion of node in linked list
    //insertion at head,tail and middle
    
    //Insertion at head
    //create new node, newNode->next = head, head= newNode
    insertionAtHead(head,tail,500);
    insertionAtTail(head,tail,600);     //Insertion at tail
    //insertion in middle
    insertionAtMiddle(head,tail,1000,10);
    printLinkedList(head); 
    
    return 0;
}