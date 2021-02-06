class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int k=0;
        for(int i=0;i<pushed.size();i++) {
            while(!s.empty() and popped[k]==s.top()) {
                s.pop();
                k++;
            }
            s.push(pushed[i]);
        }
        while(!s.empty() and popped[k]==s.top()) {
            s.pop();
            k++;
        }
        return s.empty();
    }
};