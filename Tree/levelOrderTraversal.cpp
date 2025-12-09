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


void levelOrderTraversal(Node* root){
    if(root == NULL){
        cout<<"No node is present: "<<endl;
        return;
    }
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        Node* front = q.front();q.pop();
        cout<<front->data<<" ";
        if(front->left != NULL){
            q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
    }
}


int main(){
    Node* root = createTree();
    cout<<root->data<<endl;
    cout<<"levelOrderTraversal: ";
    levelOrderTraversal(root);
    cout<<endl;
}