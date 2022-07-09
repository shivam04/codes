string Solution::solve(string A) {
    queue<char> q;
    string ans = "";
    unordered_map<char,int> mp;
    for(char c: A) {
        mp[c] += 1;
        q.push(c);
        while (!q.empty()) {
            if (mp[q.front()] > 1)
                q.pop();
            else {
                ans+=q.front();
                break;
            }
        }
        if(q.empty())
        ans += '#';
    }
    return ans;
}
