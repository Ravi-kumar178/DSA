class Solution {
public:
    bool possibleSolution(vector<int>&stalls , int k , int mid){
        int count = 1;
        int pos = stalls[0];
        
        for(int i = 0; i < stalls.size(); i++){
            if(stalls[i]-pos >= mid){
                count++;
                pos = stalls[i];
            }
            if(count == k){
                return true;
            }
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int s = 0;
        int e = stalls[(stalls.size()-1 )] - stalls[0];
        int mid = s + (e-s)/2;
        int ans = -1;
        
        while(s <= e){
            if(possibleSolution(stalls, k, mid)){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
};