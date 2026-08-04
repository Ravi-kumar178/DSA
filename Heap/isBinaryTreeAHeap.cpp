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
	bool isHeap(Node* tree) {
		// code here
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
				if ((front->left && front->data < front->left->data) || (front->right && front->data < front->right->data))
					return false;
				
				q.push(front->left);
				q.push(front->right);
			}
		}
		return true;
	}
};
