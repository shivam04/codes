class Solution {
private:
    int power(int a) {
        int ans = 0;
        while(a!=1) {
            if(a%2==0) {
                a/=2;
            } else {
                a = 3*a+1;
            }
            ans++;
        }
        return ans;
    }
    static bool cmp(pair <int, int> a, pair <int, int> b) {
        return a.first == b.first ? (a.second < b.second) : a.first < b.first;
    }
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int> > v;
        for(int i = lo; i <= hi; i++){
            pair <int, int> r;
            r.first = power(i);
            r.second = i;
            v.push_back(r);
        }
        sort(v.begin(), v.end(), cmp);
        return v[k-1].second;
    }
};