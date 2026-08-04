class Info {
	public:
	int data;
	int rowIndex;
	int colIndex;
	
	Info(int val, int r, int c) {
		this->data = val;
		this->rowIndex = r;
		this->colIndex = c;
	}
};

class Compare{
    public:
    bool operator()(Info* a, Info* b){
        return a->data > b->data;
    }
};

class Solution {
	public:
	
	vector<int> mergeArrays(vector<vector<int>> &mat) {
		// Code here
		int totalCols = mat[0].size();
		int totalRows = mat.size();
		
		priority_queue<Info*,vector<Info*>,Compare>hp;
		
		for(int i = 0; i < totalRows; i++){
		    int ele = mat[i][0];
		    Info* temp = new Info(ele,i,0);
		    hp.push(temp);
		}
		
		vector<int>ans;
		
		while(!hp.empty()){
		    Info* front = hp.top(); hp.pop();
		    
		    int frontData = front->data;
		    int frontRowIndex = front->rowIndex;
		    int frontColIndex = front->colIndex;
		    
		    ans.push_back(frontData);
		    
		    if(frontColIndex + 1 < totalCols){
		        int ele = mat[frontRowIndex][frontColIndex+1];
		        Info* temp = new Info(ele,frontRowIndex,frontColIndex+1);
		        hp.push(temp);
		    }
		}
		return ans;
	}
};
