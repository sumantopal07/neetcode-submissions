class Solution {
public:
    vector<vector<int>> subsets(vector<int>& ar) {
        
        vector<vector<int>> answers;
        int n=ar.size();
        for(int i=0;i<(1<<n);i++) {
            vector<int> answer;
            for(int j=0;j<n;j++) {
                if((i & (1<<j))!=0) {
                    answer.push_back(ar[j]);
                }
            }
            answers.push_back(answer);
        }
        return answers;
        
    }
};
