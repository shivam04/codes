string Solution::solve(int A) {
    queue<string> q;
    int t = A;
    q.push("");
    int cnt = 0;
    while(t--) {
        queue<string> tq = q;
        queue<string> pq;
        while(!tq.empty()) {
            string tt = tq.front();
            tq.pop();
            string pt = "1" + tt + "1";
            pq.push(pt);
            cnt++;
            if(cnt==A)
                return pt;
        }
        tq = q;
        while(!tq.empty()) {
            string tt = tq.front();
            tq.pop();
            string pt = "2" + tt + "2";
            pq.push(pt);
            cnt++;
            if(cnt==A)
                return pt;
        }
        q = pq;
    }
    return "";
}
