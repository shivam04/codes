class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for(int i=1;i<n;i++) {
            int a = 0, b = 0, c = 0, d = 0;
            for(int j=0;j<i;j++) {
                if(rating[i] < rating[j]) a++;
                if(rating[i] > rating[j]) b++;
            }
            for(int k=i+1;k<n;k++) {
                if(rating[i] > rating[k]) c++;
                if(rating[i] < rating[k]) d++;
            }
            ans += (a*c + b*d);
        }
        return ans;
    }
};