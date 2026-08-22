class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>maxHeap;
        maxHeap.push(a);
        maxHeap.push(b);
        maxHeap.push(c);
        int totalScore = 0;

        while(maxHeap.size() > 1){
            int first = maxHeap.top(); maxHeap.pop();
            int second = maxHeap.top(); maxHeap.pop();
            first--;
            second--;
            totalScore++;
            if(first > 0) maxHeap.push(first);
            if(second > 0) maxHeap.push(second);
        }
        return totalScore;
    }
};