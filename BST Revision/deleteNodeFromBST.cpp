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

int max(Node* root){
    if(!root) return -1;

    while(root->right) root = root->right;

    return root->data;
}

Node* deleteNodeFromBST(Node* root, int target){
    if(!root) return root;

    if(target == root->data){
        if(!root->left && !root->right){
            delete root;
            return nullptr;
        }
        else if(!root->left && root->right){
            Node* childNode = root->right;
            root->right = nullptr;
            delete root;
            return childNode;
        }
        else if(root->left && !root->right){
            Node* childNode = root->left;
            root->left = nullptr;
            delete root;
            return childNode;
        }
        else{
            int maxValue = max(root->left); 
            root->data = maxValue;
            root->left = deleteNodeFromBST(root->left,maxValue);
            return root;
        }
    }
    else if(target > root->data){
       root->right = deleteNodeFromBST(root->right,target);
    }
    else{
        root->left = deleteNodeFromBST(root->left,target);
    }
    return root;
}

int main(){
    Node* root = nullptr;
    createTree(root);
    levelOrderTraversal(root);
    cout<<endl;
    int target = 100;
    root = deleteNodeFromBST(root,target);
    levelOrderTraversal(root);
    return 0;
}