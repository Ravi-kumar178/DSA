#include<iostream>
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

Node* createTree(){
    int data;
    cin>>data;

    if(data == -1) return nullptr;

    Node* newNode = new Node(data);

    newNode->left = createTree();
    newNode->right = createTree();

    return newNode;
}

int main(){
    Node* root = createTree();
    cout<<root->data<<endl;
    return 0;
}