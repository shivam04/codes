int Solution::solve(int A) {
    stack<int> b;
    int temp = A;
    while(temp) {
        b.push(temp%2);
        temp >>= 1;
    }
    stack<int> ss = b;
    int p = b.size();
    int q = p;
    int x = 0;
    int i = 0;
    while(!b.empty()) {
        if(b.top()==0) {
            x += (1<<(p-1));
        }
        b.pop();
        p--;
    }
    int y = 1<<q;
    return x^y;
}
