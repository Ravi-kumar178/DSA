class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        //sort deck
        sort(deck.begin(),deck.end());
        //init q, ans
        queue<int>q;
        vector<int>ans(deck.size());
        //push i=0->n-1 into q
        for(int i = 0; i < deck.size(); i++){
            q.push(i);
        }
        //for loop on deck and fill ans with stimulation
        for(int i = 0; i < deck.size(); i++){
            ans[q.front()] = deck[i]; q.pop();
            if(!q.empty()){
                int temp = q.front(); q.pop();
                q.push(temp);
            }
        }
        return ans;
    }
};