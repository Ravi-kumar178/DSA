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

   while (temp != nullptr)
   {
      cout << temp->data <<(temp->next != nullptr ? " -> " : " -> NULL\n");
      temp = temp->next;
      count++;
   }
   cout<<"Number of nodes: "<<count<<endl;
   return;
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

   return 0;
}