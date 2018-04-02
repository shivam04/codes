string Solution::fractionToDecimal(int A, int B) {
    if(A==0)
    return "0";
    long long a,b;
    int sign=1;
    string sgn="";
    if(A<0)
    sign*=-1;
    if(B<0)
    sign*=-1;
    if(sign==-1)
    sgn="-";
    a = abs((long)A);
    b = abs((long)B);
    if(a%b==0){
        return sgn+to_string(a/b);
    }
    unordered_map<int,int> mp;
    int n = a/b;
    a = a%b;
    int val;
    string ans = to_string(n)+".";
    while(a){
        a = a*10;
        if(mp.find(a)!=mp.end()){
            val = mp[a];
            break;
        }else{
            mp[a] = ans.size();
        }
        int n = a/b;
        a = a%b;
        ans+=to_string(n);
    }
    if(a==0)
    return sgn+ans;
    else{
        ans = ans+")";
        ans.insert(val,"(");
        return sgn+ans;
    }
}
