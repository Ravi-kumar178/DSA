#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *insertIntoBST(Node *root, int data)
{
    if (!root)
    {
        Node *newNode = new Node(data);
        return newNode;
    }

    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
        root->left = insertIntoBST(root->left, data);

    return root;
}

void createBst(Node *&root)
{
    cout << "Enter data: " << endl;
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
    return;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        cout << front->data << " ";
        if (front->left)
            q.push(front->left);
        if (front->right)
            q.push(front->right);
    }
    return;
}

void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    return;
}
void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    return;
}
void postorder(Node *root)
{
    if (!root)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";

    return;
}

int main()
{
    Node *root = nullptr;
    createBst(root);
    levelOrderTraversal(root);
    cout << endl;
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    return 0;
}