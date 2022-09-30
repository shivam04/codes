int Solution::solve(int A) {
    vector<int> c;
    int i=1;
    while(i<=A) {
        c.push_back(i);
        i*=5;
    }
    int w = 0;
    int k = c.size()-1;
    while(A) {
        A -= c[k];
        w++;
        while(c[k]>A) {
            k--;
        }
    }
    return w;
}
