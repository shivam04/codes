int toDecimal(string n){
    string num = n;
    int dec_value = 0;
    int base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}
vector<string> grayCodeUtil(int n) {
    if(n<=0)
        return {"0"};
    if(n==1)
        return {"0", "1"};
    vector<string> recAns=grayCodeUtil(n-1);
    vector<string> mainAns;
    for(int i=0;i<recAns.size();i++) {
      string s=recAns[i];
      mainAns.push_back("0"+s);
    }
    for(int i=recAns.size()-1;i>=0;i--) {
       string s=recAns[i];
       mainAns.push_back("1"+s);
    }
    return mainAns;
}
vector<int> Solution::grayCode(int A) {
    vector<string> arr = grayCodeUtil(A);
    vector<int> ans;
    for(string a: arr) {
        ans.push_back(toDecimal(a));
    }
    return ans;
}
