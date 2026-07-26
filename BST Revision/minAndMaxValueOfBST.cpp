#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insertIntoBst(Node* root, int val){
    if(!root){
        Node* newNode = new Node(val);
        return newNode;
    }

    if(val > root->data){
        root->right = insertIntoBst(root->right,val);
    }
    else root->left = insertIntoBst(root->left,val);

    return root;
}

void createTree(Node* &root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBst(root,data);
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

int min(Node* root){
    if(!root) return -1;

    while(root->left){
        root = root->left;
    }

    return root->data;
}

int max(Node* root){
    if(!root) return -1;

    while(root->right){
        root = root->right;
    }
    return root->data;
}

int main(){
    Node* root = nullptr;
    createTree(root);
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"Nodes with min value in tree is: "<<min(root)<<endl;
    cout<<"Nodes with max value in tree is: "<<max(root)<<endl;
    return 0;
}