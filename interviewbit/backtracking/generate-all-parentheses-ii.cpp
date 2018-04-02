void ans(vector<string> &v,int s,int a,int o,int c){
    static char ss[100005];
    if(c==a){
        string p(ss);
        v.push_back(p);
        return ;
    }
    if(o<a){
        ss[s] = '(';
        ans(v,s+1,a,o+1,c);
    }if(o>c){
        ss[s] = ')';
        ans(v,s+1,a,o,c+1);
    }
}
vector<string> Solution::generateParenthesis(int A) {
    vector<string> v;
    ans(v,0,A,0,0);
    return v;
}
