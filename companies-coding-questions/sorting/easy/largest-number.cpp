string Solution::largestNumber(const vector<int> &A) {
    vector<string> sA;
        string ans = ""; 
        for(int n : A) {
            string p = to_string(n);
            sA.push_back(p);
        }
        sort(sA.begin(), sA.end(), [](string a, string b) {
            string ab = a+b;
            string ba = b+a;
            return ab>ba;
        });
        for(string a: sA) {
            ans = ans + a;
        }
        int p = 0;
        while(p<ans.size() and ans[p]=='0') {
            p++;
        }
        p = p==0 ? 0 : p-1;
        return ans.substr(p);
}
