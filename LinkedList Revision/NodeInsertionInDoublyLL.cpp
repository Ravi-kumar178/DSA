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

void insertNodeAtHead(int data, Node *&head, Node *&tail)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    return;
}

void insertNodeAtTail(int data, Node *&head, Node *&tail)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    return;
}

void insertNodeAtAnyPosition(int data, Node *&head, Node *&tail, int position)
{
    int length = getLength(head);
    if(position < 1){
        cout<<"The position of node can't be less than one"<<endl;
    }
    else if(position == 1){
        //insert at head
        insertNodeAtHead(data,head,tail);
    }
    else if(position > length){
        cout<<"It can't be possible"<<endl;
    }
    else if(position == length){
        //insert at tail
        insertNodeAtTail(data,head,tail);
    }
    else{
        Node* newNode = new Node(data);
        Node* previous = NULL;
        Node* current = head;

        while(position != 1){
            previous = current;
            current = current->next;
            position--;
        }

        previous->next = newNode;
        newNode->prev = previous;
        newNode->next = current;
        current->prev = newNode;
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
    // insertNodeAtHead(100, head, tail);
    // printingDoublyLinkedList(head);
    // insertNodeAtTail(100, head, tail);
    // printingDoublyLinkedList(head);

    int position = 3;
    insertNodeAtAnyPosition(100,head,tail,position);
    printingDoublyLinkedList(head);

    return 0;
}