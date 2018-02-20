string Solution::countAndSay(int A) {
    //string ss[] = {"1","11","21","1211"};
    vector<string> s;
    s.push_back("1");
    s.push_back("11");
    s.push_back("21");
    s.push_back("1211");
    if(A<=4){
        return s[A-1];
    }
    int i = 4;
    while(i<A){
        string aa = "";
        for(int j=0;j<s[i-1].length();j++){
            int c = 0;
            char p = (s[i-1][j]);
            while(s[i-1][j]==p and j<s[i-1].length()){
                j++;
                c++;
            }
            aa = aa+to_string(c);
            aa = aa+p;
            j-=1;
        }
        //cout<<aa<<"\n";
        s.push_back(aa);
        i++;
    }
    //cout<<s[A-1]<<"\n";
    return s[A-1];
}
