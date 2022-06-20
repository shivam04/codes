int Solution::solve(int A, string B) {
    map<char,int> mp;
    for(char c: B) {
        mp[c]++;
    }
    for(auto it: mp) {
        int l = it.second;
        if(l%A!=0)
            return -1;
    }
    return 1;
}
