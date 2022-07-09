vector<int> Solution::solve(int A) {
    if(A==1)
        return {1};
    if(A==2)
        return {1,2};
    if(A==3)
        return {1,2,3};    

    queue<int> qq;
    qq.push(1);
    qq.push(2);
    qq.push(3);
    A = A-3;
    vector<int> ans = {1,2,3};
    while(A>0) {
        int t = qq.front();
        qq.pop();
        int p = t*10+1;
        int q = t*10+2;
        int r = t*10+3;
        qq.push(p);
        A--;
        ans.push_back(p);
        if(A==0)
            return ans;
        qq.push(q);
        A--;
        ans.push_back(q);
        if(A==0)
            return ans;
        qq.push(r);
        A--;
        ans.push_back(r);
        if(A==0)
            return ans;
    }
    return ans;
}
