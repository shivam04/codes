class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int start = 1, num = 1, lvl=1;
        while(num < label) {
            num = num * 2 + 1;
            start = 2*start;
            lvl++;
        }
        vector<int> res(lvl);
        while(lvl > 0) {
            res[lvl-1] = label;
            if(lvl%2 == 0) {
                label = 3*start-1-label;
            }
            label=label/2;
            start=start/2;
            lvl--;
            if(lvl%2==0) {
                label = 3*start-1-label;
            }
        }
        return res;
    }
};