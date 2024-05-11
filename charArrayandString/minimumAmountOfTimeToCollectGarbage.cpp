class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickP = 0;
        int pickG = 0;
        int pickM = 0;

        int travelP = 0;
        int travelG = 0;
        int travelM = 0;

        int lastP = 0;
        int lastG = 0;
        int lastM = 0;

        for(int i = 0; i < garbage.size(); i++){
            string curr = garbage[i];
            for(int j = 0; j < curr.size(); j++){
                char ch = curr[j];
                if(ch == 'G'){
                    pickG++;
                    lastG = i;
                }
                else if(ch == 'P'){
                    pickP++;
                    lastP = i;
                }
                else{
                    pickM++;
                    lastM = i;
                }
            }
        }

        //calculate traveling time
        for(int i = 0; i < lastG; i++){
            travelG = travelG + travel[i];
        }
        for(int i = 0; i < lastP; i++){
            travelP = travelP + travel[i];
        }
        for(int i = 0; i < lastM; i++){
            travelM = travelM + travel[i];
        }

        int totalTime = (pickG + travelG)+(pickP + travelP)+(pickM + travelM);
        return totalTime;
    }
};