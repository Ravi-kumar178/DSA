class Solution {
	public:
	
	void reverse(queue<int>& q, stack<int>& st, int k) {
		if (k == 0) {
			while (!q.empty()) {
				int front = q.front(); q.pop();
				st.push(front);
			}
			return;
		}
		
		int front = q.front(); q.pop();
		k--;
		reverse(q, st, k);
		q.push(front);
		return;
	}
	
	void reverseStack(stack<int>& st) {
		stack<int>s;
		while (!st.empty()) {
			s.push(st.top());
			st.pop();
		}
		st = s;
		return;
	}
	
	queue<int> reverseFirstK(queue<int> q, int k) {
		// code here
		if (k > q.size())
			return q;
		stack<int>st;
		
		reverse(q, st, k);
		
		if (st.empty())
			return q;
		
		reverseStack(st);
		
		while (!st.empty()) {
			int top = st.top();
			st.pop();
			q.push(top);
		}
		return q;
	}
};
