void pairSort(vector<int> a, vector<int>& b, int n) {
    vector<pair<int,int>> pairt(n);
    for(int i=0;i<n;i++) {
        pairt[i].first = a[i];
        pairt[i].second = b[i];
    }
    sort(pairt.begin(), pairt.end());
    for(int i=0;i<n;i++) {
        b[i] = pairt[i].second;
    }
    reverse(b.begin(), b.end());
}
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int n = A.size();
        vector<int> ans;
        vector<int> B(n);
        for(int i=0;i<n;i++) {
            B[i] = i+1;
        }
        pairSort(A, B, n); 
        for(int i : B) {
            for(int f : ans) {
                if(i<=f)
                    i = f + 1 - i;
            }
            ans.push_back(i);
            ans.push_back(n--);
        }
        return ans;
    }
};