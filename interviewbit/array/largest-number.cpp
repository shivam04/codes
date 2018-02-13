int cmp(string a,string b){
    string ab = a+b;
    string ba = b+a;
    return ab.compare(ba)>0?1:0;
}
string Solution::largestNumber(const vector<int> &A) {
    vector<string> v;
    int n = A.size();
    string p="";
    for(int i=0;i<n;i++){
        /*cout<<to_string(A[i])<<" ";*/
         //p += std::to_string(A[i]);
        //cout<<p<<"";
        v.push_back(to_string(A[i]));
    }
    
    sort(v.begin(),v.end(),cmp);
    int flag = 0;
    for(int i=0;i<n;i++){
        if(v[i]=="0" and flag==0){
            continue;
        }else{
            flag = 1;
            p+=v[i];
        }
    }
    if(p=="")
    return "0";
    return p;
}
