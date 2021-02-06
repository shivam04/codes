class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int j=0;
        int ans = 0;
        for(int i=0;i<A.size();i++) {
            if(A[i]==0) K--;
            while(j<=i and K<0) {
                if(A[j]==0) 
                    K++;
                j++;
            }
            ans = max(i-j+1, ans);
        }
        return ans;
    }
};