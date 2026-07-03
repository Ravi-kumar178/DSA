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
    Node(int _val)
    {
        this->data = _val;
        this->next = nullptr;
    }

    ~Node()
    {
        cout << "Destructor called of node: " << this->data << " " << this->next << endl;
    }
};

void printLinkedList(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << (temp->next != NULL ? " -> " : " -> NULL \n");
        temp = temp->next;
    }
    return;
}

int getLength(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteNodeAtHead(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "There is no node present to get removed" << endl;
        return;
    }
    else if (head == tail)
    {
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    return;
}

void deleteNodeAtTail(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "There is no node present to get removed" << endl;
        return;
    }
    else if (head == tail)
    {
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        while (curr->next->next != NULL)
        { // curr->next != tail
            curr = curr->next;
        }
        Node *temp = tail;
        tail = curr;
        tail->next = nullptr;
        delete temp;
    }
}

void deleteNodeAtAnyPosition(Node *&head, Node *&tail, int position)
{
    int nodeLength = getLength(head);
    if (position < 1)
    {
        cout << "You can't delete the node that is positioned earlier than 1st position" << endl;
    }
    else if (position == 1)
    {
        // deleteAtHead
        deleteNodeAtHead(head, tail);
    }
    else if (position > nodeLength)
    {
        cout << "you can't delete the node that is positioned at greater than tail" << endl;
    }
    else if (position == nodeLength)
    {
        // delete at tail
        deleteNodeAtTail(head, tail);
    }
    else
    {
        // delete in between
        Node *prev = NULL;
        Node *curr = head;

        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
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
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    Node *head = first;
    Node *tail = fifth;

    printLinkedList(head);
    // deleteNodeAtHead(head, tail);
    // printLinkedList(head);
    // deleteNodeAtTail(head, tail);
    // printLinkedList(head);

    int position = 3;
    deleteNodeAtAnyPosition(head, tail, position);
    printLinkedList(head);
    return 0;
}