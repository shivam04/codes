class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        vector<int> res(n,0);
        int c1=0,c2=0;
        for(int i=0;i<n;i++) {
            if(seq[i]=='(') {
                if(c1<c2) {
                    c1+=1;
                } else {
                    c2+=1;
                    res[i]=1;
                }
            } else {
                if(c1>c2) {
                    c1-=1;
                } else {
                    c2-=1;
                    res[i]=1;
                }
            }
        }
        return res;
    }
};