#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->next = nullptr;
    }

    Node(int val)
    {
        this->data = val;
        this->next = nullptr;
    }
};

int getLength(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;

}

void printLinkedList(Node* &head){
    Node* temp = head;

    while(temp != nullptr){
        cout<<temp->data<<(temp->next != nullptr ? "->":"-> NULL \n");
        temp = temp->next;
    }
    return;
}

void InsertAtHead(int data,Node* &head, Node* &tail){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    return;
}

void InsertAtTail(int data, Node*& head, Node* &tail){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
    return;
}

void InsertAtAnyPosition(int data, Node* &head, Node* &tail, int position){
    int lengthOfNode = getLength(head);
    if(position < 1){
        cout<<"you can't positioned any node earlier than 1st position"<<endl;
        return;
    }
    else if(position == 1){
        //insert at head
        InsertAtHead(data,head,tail);
    }
    else if(position == lengthOfNode){
        //insert at tail
        InsertAtTail(data,head,tail);
    }
    else if(position > lengthOfNode){
        cout<<"you can maximize positioned any node at the tail"<<endl;
        return;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        while(position != 1){
            prev = curr;
            curr = curr->next;
            position--;
        }
        Node* newNode = new Node(data);
        prev->next = newNode;
        newNode->next = curr;
    }
    return;

}

int main()
{
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

    int data = 100;
    printLinkedList(head);
    // InsertAtHead(data,head,tail);
    // printLinkedList(head);
    // InsertAtTail(data,head,tail);
    // printLinkedList(head);
    int position = 4;
    InsertAtAnyPosition(data, head, tail, position);
    printLinkedList(head);

    return 0;
}