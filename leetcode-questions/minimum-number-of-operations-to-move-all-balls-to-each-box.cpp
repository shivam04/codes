class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n,0);
        int m = 0;
        int cnt = 0;
        for(int i=0;i<n;i++) {
            res[i] += m;
            if(boxes[i]=='1') {
                cnt++;
            }
            m+=cnt;
        }
        m=0;
        cnt = 0;
        for(int i=n-1;i>=0;i--) {
            res[i] += m;
            if(boxes[i]=='1') {
                cnt++;
            }
            m+=cnt;
        }
        return res;
    }
};