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
    cout<<"Enter the val of node: ";
    cin>>data;
    
    if(data == -1){
        return NULL;
    }
    
    Node* root = new Node(data);
    
    cout<<"left of node: "<<data<<endl;
    root->left = createTree();
    
    cout<<"Back to "<<data<<" from LEFT\n";
    cout<<"right of node: "<<data<<endl;
    root->right = createTree();
    cout<<"Back to "<<data<<" from RIGHT\n";
    return root;
}

int main(){
    Node* tree = createTree();
    return 0;
}