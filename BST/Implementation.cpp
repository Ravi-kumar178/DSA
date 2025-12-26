#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBst(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    else{
        if(data > root->data){
            root->right = insertIntoBst(root->right,data);
        }
        else{
            root->left = insertIntoBst(root->left,data);
        }
    }
    return root;
}

void createTree(Node* &root){
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    
    while(data != -1){
        root = insertIntoBst(root,data);
        cout<<"Enter the data: ";
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){
    if(!root) return;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    
    while(q.size()>1){
        Node* front = q.front();
        q.pop();
        
        if(!front){
            cout<<endl;
            q.push(NULL);
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
    Node* root = NULL;
    createTree(root);
    cout<<endl<<endl<<"levelOrderTraversal: "<<endl;
    levelOrderTraversal(root);
}