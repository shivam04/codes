int countPF(int n) {
    set<int> s;

    while(n%2==0) {
        s.insert(2);
        n/=2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while(n%i==0) {
            n/=i;
            s.insert(i);
        }
    }
    if(n>2)
        s.insert(n);
    return s.size();
}
int Solution::solve(int A) {
    int ans = 0;
    for(int i=1;i<=A;i++) {
        if(countPF(i)==2)
            ans++;
    }
    return ans;
}