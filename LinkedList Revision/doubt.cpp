#include <iostream>
using namespace std;

class Node
{
public:
   int data;
   Node *next;

   Node()
   {
      this->next = NULL;
   }

   Node(int _data)
   {
      this->data = _data;
      this->next = nullptr;
   }
};

void printLinkedList(Node *&head)
{
   Node *temp = head;
   int count = 0;

   while (temp)
   {
      cout << temp->data <<(temp->next != nullptr ? " -> " : " -> NULL\n");
      temp = temp->next;
      count++;
   }
   cout<<"Number of nodes: "<<count<<endl;
   return;
}

void creatingNewNode(Node* &head){
    Node* temp = head;
    Node* second = nullptr;
    while(temp != NULL){
        if(temp->next == nullptr) second = temp;
        temp = temp->next;
    }
    second->next = new Node(100);
}

int main()
{
   // Node a(10); //static node creation

   Node *first = new Node(10);
   Node *second = new Node(20);
   Node *third = new Node(30);
   Node *fourth = new Node(40);
   Node *fifth = new Node(50);

   first->next = second;
   second->next = third;
   third->next = fourth;
   fourth->next = fifth;

   Node *head = first;
   Node *tail = second;

   printLinkedList(head);
   creatingNewNode(head);
   printLinkedList(head);

   return 0;
}