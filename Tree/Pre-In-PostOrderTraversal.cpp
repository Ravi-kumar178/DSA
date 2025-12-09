#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createTree(){
    int data;
    cin>>data;
    
    if(data == -1){
        return NULL;
    }
    
    Node* root = new Node(data);
    root->left = createTree();
    root->right = createTree();
    return root;
}

void preOrder(Node* root){
    //base case 
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    //base case
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root = createTree();
    cout<<root->data<<endl;
    cout<<"PreOrder: "<<endl;
    preOrder(root);
    cout<<endl;
    cout<<"Inorder: "<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"postOrder: "<<endl;
    postOrder(root);
    cout<<endl;
}