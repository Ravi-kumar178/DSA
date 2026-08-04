/*
class Node {
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int val) {
		data = val;
		left = right = NULL;
	}
};
*/

class Solution {
	public:
	bool isCBT(Node* tree) {
		queue<Node*>q;
		q.push(tree);
		
		bool isNullPresent = false;
		
		while (!q.empty()) {
			Node* front = q.front(); q.pop();
			
			if (!front)
				isNullPresent = true;
			else {
				if (isNullPresent)
					return false;
				q.push(front->left);
				q.push(front->right);
			}
		}
		return true;
	}
	
	bool foundHeap(Node* root){
	    if(!root) return true;
	    if(!root->left && !root->right) return true;
	    
	    if((root->left && root->data < root->left->data) || (root->right && root->data < root->right->data))
	        return false;
	   
	   bool leftAns = foundHeap(root->left);
	   bool rightAns = foundHeap(root->right);
	   
	   return leftAns && rightAns;
	        
	}
	bool isHeap(Node* tree) {
		// code here
		return isCBT(tree)&&foundHeap(tree);
		
	}
};
