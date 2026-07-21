#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int data){
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* createTree(){
    int data;
    cin >> data;

    if(data == -1) return nullptr;

    Node* newNode = new Node(data);
    newNode->left = createTree();
    newNode->right = createTree();
    return newNode;
}

void preOrder(Node* root){
    if(root == nullptr) return;

    cout<<root->val<<" ";
    // if(root->left != nullptr || root->right != nullptr) cout<<" , ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}

void inOrder(Node* root){
    if(root == nullptr) return;

    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);

    return;
}

void postOrder(Node* root){
    if(root == nullptr) return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";

    return;
}

int main(){
    Node* root = createTree();

    cout<<"PreOrder Traversal: "<<endl;
    preOrder(root);

    cout<<"InOrder Traversal: "<<endl;
    inOrder(root);

    cout<<"PostOrder Traversal: "<<endl;
    postOrder(root);
    
    return 0;
}