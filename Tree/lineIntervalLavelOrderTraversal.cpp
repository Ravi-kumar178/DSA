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

void lineIntervalLevelOrderTraversal(Node* root){
    if(!root){
        cout<<"No node is present "<<endl;
        return;
    }
    
    queue<Node*>q;
    q.push(root);
    q.push(0);
    
    while(q.size() > 1){
        Node* front = q.front(); q.pop();
        
        if(!front){
            cout<<endl;
            q.push(front);
        }
        else{
            cout<<front->data<<" ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
}


int main(){
    Node* root = createTree();
    //cout<<root->data<<endl;
    cout<<"levelOrderTraversal: ";
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"lineIntervalLevelOrderTraversal: "<<endl;
    lineIntervalLevelOrderTraversal(root);
    cout<<endl;
}