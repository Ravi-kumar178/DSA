class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>maxHeap;
        maxHeap.push(a);
        maxHeap.push(b);
        maxHeap.push(c);

        int totalScore = 0;
        while(maxHeap.size() > 1){
            int pile1 = maxHeap.top(); maxHeap.pop();
            int pile2 = maxHeap.top(); maxHeap.pop();
            totalScore += 1;
            pile1--; pile2--;

            if(pile1 > 0) maxHeap.push(pile1);
            if(pile2 > 0) maxHeap.push(pile2);
        }
        return totalScore;
    }
};