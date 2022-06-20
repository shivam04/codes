int Solution::solve(string A, string B) {
    int n = A.size();
    unordered_map<int,int> mp;
    int m = B.size();
    for(char c: A) {
        mp[c]++;
    }
    int cnt = 0;
    unordered_map<int,int> mpb;
    string temp = "";
    for(int i=0;i<n;i++) {
       mpb[B[i]]++;
    }
    int ok = 1;
    for(auto it: mp) {
        char x = it.first;
        if(mpb[x] != it.second) {
            ok = 0;
            break;
        }
    }
    cnt += ok;

    for(int i=n;i<m;i++) {
        mpb[B[i-n]]--;
        mpb[B[i]]++;
        int ok = 1;
        for(auto it: mp) {
            char x = it.first;
            if(mpb[x] != it.second) {
                ok = 0;
                break;
            }
        }
        cnt += ok;
    }
    return cnt;
    
}
