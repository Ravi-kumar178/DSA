class Info{
    public:
    int x;
    int y;
    long long dist;

    Info(int val1, int val2){
        this->x = val1;
        this->y = val2;
        this->dist = pow(val1,2)+pow(val2,2);
    }
};

class Compare{
    public:
    bool operator()(Info* x, Info* y){
        return x->dist < y->dist;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Info*,vector<Info*>,Compare>maxHeap;
        for(int i = 0; i < k; i++){
            int val1 = points[i][0];
            int val2 = points[i][1];
            Info* temp = new Info(val1,val2);
            maxHeap.push(temp);
        }

        for(int i = k; i < points.size(); i++){
            int val1 = points[i][0];
            int val2 = points[i][1];
            long long squareNum = pow(val1,2)+pow(val2,2);

            if(squareNum < maxHeap.top()->dist){
                Info* temp = new Info(val1,val2);
                maxHeap.pop();
                maxHeap.push(temp);
            }
        }

        vector<vector<int>>ans;
        while(!maxHeap.empty()){
            Info* temp = maxHeap.top(); maxHeap.pop();
            ans.push_back({temp->x,temp->y});
        }
        return ans;
    }
};