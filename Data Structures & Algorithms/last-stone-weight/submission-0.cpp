class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int &i: stones)
            maxHeap.push(i);

        while(!maxHeap.empty()) {
            int x = maxHeap.top();
            maxHeap.pop();
            if(maxHeap.empty())
                return x;
            int y = maxHeap.top();
            maxHeap.pop();
            if(x<y)
                maxHeap.push(y-x);
            if(y<x)
                maxHeap.push(x-y);
        }
        return 0;
        
    }
};
