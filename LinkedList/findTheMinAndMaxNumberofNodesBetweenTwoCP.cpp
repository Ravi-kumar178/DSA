class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans = {-1,-1};
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nxt = head->next->next;
        if(!nxt) return ans;

        int i = 2;
        int firstCP = -1;
        int lastCP = -1;
        int minDistance = INT_MAX;
        
        //traverse over ll
        while(nxt){
            if((curr->val > prev->val && curr->val > nxt->val) ||
                (curr->val < prev->val && curr->val < nxt->val)
            ){
                if(firstCP == -1){
                    firstCP = i;
                    lastCP = i;
                }
                else{
                   minDistance = min(minDistance, i-lastCP);
                   lastCP = i; 
                }
            }
            i++;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        if(firstCP == -1 || firstCP == lastCP) return ans;

        ans[0] = minDistance;
        ans[1] = lastCP-firstCP;
        return ans;
    }
};