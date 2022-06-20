int Solution::solve(string A) {
    unordered_map<char,int> mp;
    for(auto c: A) {
        mp[c]++;
    }
    int cntOdd = 0;
    for(auto it: mp) {
        cntOdd += (it.second%2);
    }
    return cntOdd<=1;
}