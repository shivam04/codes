bool isPalin(string t) {
    string p = t;
    reverse(p.begin(), p.end());
    return t == p;
}
int Solution::anytwo(string A) {
    unordered_map<char, int> freq;
    for(char c: A) {
        freq[c]++;
        if(freq[c] > 2) {
            return 1;
        }
    }
    string t = "";
    for(char c: A) {
        if(freq[c]>1) {
            t += c;
        }
    }
    if(isPalin(t)) {
        if(t.length()%2==1) {
            int k = t.length();
            return t[k/2] == t[k/2-1];
        }
        return 0;
    }
    return 1;
}
