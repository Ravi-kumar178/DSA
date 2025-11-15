#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    
    Node(){
        this->prev = NULL;
        this->next = NULL;
    }
    
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printLL(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

//insertion in doubly ll
void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        //if ll is empty;
        //create new Node
        Node* newNode = new Node(data);
        //fix head and tail
        head = newNode;
        tail = newNode;
    }
    else{
        //ll not empty
        //create new Node
        Node* newNode = new Node(data);
        //fix newNode->next = head and head->prev = newNode
        newNode->next = head;
        head->prev = newNode;
        //head = newNode
        head = newNode;
    }
}

void insertAtTail(Node* &head,Node* &tail,int data){
    if(head == NULL){
        //create new Node
        Node* newNode = new Node(data);
        //head = newNode && tail = newNode
        head = newNode;
        tail = newNode;
    }
    else{
        //create newNode
        Node* newNode = new Node(data);
        //point tail->next = newNode && newNode->prev = tail 
        tail->next = newNode;
        newNode->prev = tail;
        //tail = newNode
        tail = newNode;
    }
}

int getLength(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    int len = getLength(head);
    if(position == 1){
        insertAtHead(head,tail,data);
    }
    else if(position == len+1){
        insertAtTail(head,tail,data);
    }
    else{
        //create new Node
        Node* newNode = new Node(data);
        //set pointer prevNode and currNode
        Node* prevNode = NULL;
        Node* currNode = head;
        while(position != 1){
            prevNode = currNode;
            currNode = currNode->next;
            position--;
        }
        //set relation between prevNode,newNode and currNode
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = currNode;
        currNode->prev = newNode;
    }
}

//deletion in doubly ll
void deleteNodes(Node* &head, Node* &tail, int position){
    int len = getLength(head);
    if(head == NULL){
        cout<<"Cann't delete, because there is no node present."<<endl;
        return;
    }
    if(head == tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    else{
        if(position == 1){
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
        }
        else if(position == len){
            //delete from tail
            Node* prevNode = tail->prev;
            prevNode->next = NULL;
            tail->prev = NULL;
            delete tail;
            tail = prevNode;
        }
        else{
            Node* prevNode = NULL;
            Node* currNode = head;
            while(position != 1){
                prevNode = currNode;
                currNode = currNode->next;
                position--;
            }
            Node* nextNode = currNode->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            currNode->prev = NULL;
            currNode->next = NULL;
            delete currNode;
        }
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    
    insertAtHead(head,tail,50);
    // insertAtHead(head,tail,40);
    // insertAtHead(head,tail,30);
    // insertAtHead(head,tail,20);
    // insertAtHead(head,tail,10);
    // insertAtTail(head,tail,60);

    printLL(head);
    
    //deletion
    deleteNodes(head,tail,3);
    printLL(head);
    cout<<head<<"->"<<tail<<endl;
    
    return 0;
}