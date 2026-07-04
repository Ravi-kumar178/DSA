#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        this->next = NULL;
        this->prev = NULL;
    }

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node(){
        cout<<"Node is deleted: "<<this->data<<endl;
    }
};

void printingDoublyLinkedList(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << (temp->next != NULL ? " -> " : " -> NULL\n");
        temp = temp->next;
    }
    delete temp;
}

int getLength(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteNodeAtHead(Node* &head, Node* &tail){
    if(head == NULL){
        cout<<"There is no node present to get deleted"<<endl;
    }
    else if(head == tail){
        delete head;
        head = NULL;
        tail = NULL;
    }
    else{
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    return;
}

void deleteNodeAtTail(Node* &head, Node* &tail){
    if(head == NULL){
        cout<<"There is no node present to get deleted"<<endl;
    }
    else if(head == tail){
        delete head;
        head = NULL;
        tail = NULL;
    }
    else{
        Node* temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
    }
    return;
}

void deleteNodeAtAnyPosition(Node* &head, Node* &tail, int position){
    int length = getLength(head);
    if(position < 1){
        cout<<"Not possible"<<endl;
    }
    else if(position == 1){
        deleteNodeAtHead(head,tail);
    }
    else if(position > length){
        cout<<"Not possible"<<endl;
    }
    else if(position == length){
        deleteNodeAtTail(head,tail);
    }
    else{
        Node* previous = NULL;
        Node* current = head;

        while(position != 1){
            previous = current;
            current = current->next;
            position--;
        }
        Node* temp = current->next;

        previous->next = temp;
        temp->prev = previous;
        current->prev = NULL;
        current->next = NULL;
        delete current;
    }
    return;
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    Node *head = first;
    Node *tail = fifth;

    printingDoublyLinkedList(head);
    // deleteNodeAtHead(head,tail);
    // printingDoublyLinkedList(head);
    // deleteNodeAtTail(head,tail);
    // printingDoublyLinkedList(head);
    int position = 3;
    deleteNodeAtAnyPosition(head,tail,position);
    printingDoublyLinkedList(head);

    return 0;
}