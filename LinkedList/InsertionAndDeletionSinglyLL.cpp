#include<iostream>
using namespace std;

//singly ll node 
class Node{
    public:
    int data;
    Node* next;
    
    Node(){
        this->next = NULL;
    }
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

//print LL
void printLL(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

//get length
int getLength(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        //empty LL
        //create new node
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        //create new Node
        Node* newNode = new Node(data);
        //fix pointer
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == NULL){
        //empty LL
        //create new node
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        //create new Node
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
    
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    int length = getLength(head);
    if(position <= 1){
        insertAtHead(head,tail,data);
    }
    else if(position > length){
        insertAtTail(head,tail,data);
    }
    else{
        //insert at any other position
        //create a Node
        Node* newNode = new Node(data);
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1){
            prev = curr;
            curr = curr->next;
            position--;
        }
        //fix pointer
        prev->next = newNode;
        newNode->next = curr;
    }
}

//delete
void deleteNode(Node* &head, Node* &tail, int position){
    int length = getLength(head);
    //if ll is empty
    if(head == NULL){
        cout<<"cannot be deleted, because ll is empty"<<endl;
        return;
    }
    //if single element in ll
    if(head == tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    else{
        if(position == 1){
            //delete at head
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            return;
        }
        else if(position == length){
            //delete at tail
            Node* prev = head;
            while(prev->next != tail){
                prev = prev->next;
            }
            prev->next = NULL;
            delete tail;
            tail = prev;
        }
        else{
            Node* prev = NULL;
            Node* curr = head;
            while(position != 1){
                prev = curr;
                curr = curr->next;
                position--;
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }
}

int main(){
 Node* head = NULL;
 Node* tail = NULL;
 insertAtHead(head,tail,40);
 insertAtHead(head,tail,30);
 insertAtHead(head,tail,20);
 insertAtHead(head,tail,10);
 insertAtTail(head,tail,50);
 printLL(head);
 deleteNode(head,tail,5);
 printLL(head);
 
 return 0;   
}