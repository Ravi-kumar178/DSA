#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *createTree()
{
    int data;
    cin >> data;

    if (data == -1)
        return nullptr;

    Node *newNode = new Node(data);
    newNode->left = createTree();
    newNode->right = createTree();
    return newNode;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        cout << front->val << " ";

        if (front->left)
            q.push(front->left);
        if (front->right)
            q.push(front->right);
    }
    return;
}

void levelOrderTraversal2(Node *root)
{
    queue<Node *> q;
    vector<int> arr;

    q.push(root);
    q.push(NULL);

    while (q.size() > 1)
    {
        Node *front = q.front();
        q.pop();

        if (front == nullptr)
        {
            q.push(front);
            for (int i = 0; i < arr.size(); i++)
            {
                cout << arr[i] << " ";
            }
            while (!arr.empty())
                arr.pop_back();
            cout << endl;
        }
        else
        {
            arr.push_back(front->val);
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    Node *root = createTree();

    levelOrderTraversal(root);
    cout << endl
         << endl;
    levelOrderTraversal2(root);

    return 0;
}
