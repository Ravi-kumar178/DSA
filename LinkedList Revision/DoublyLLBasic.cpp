#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int val){
        this->data = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printingDoublyLinkedList(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<(temp->next != NULL?" -> ":" -> NULL\n");
        temp = temp->next;
    }
    delete temp;
}

int getLength(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    Node* head = first;
    Node* tail = fifth;

    printingDoublyLinkedList(head);
    int LLlength = getLength(head);
    cout<<"Length of doubly LL: "<<LLlength<<endl;
    return 0;
}