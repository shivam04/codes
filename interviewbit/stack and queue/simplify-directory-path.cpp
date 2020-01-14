string Solution::simplifyPath(string A) {
    stack<string>s;
    string res;
    string dir;
    res = "";
    for(int i=0;i<A.length();i++){
        dir.clear();
        while(A[i]=='/')
        i++;
        while(i<A.length() and A[i]!='/'){
            dir.push_back(A[i]);
            i++;
        }
        if(dir.compare("..")==0){
            if(!s.empty())
            s.pop();
        }
        else if(dir.compare(".")==0)
            continue;
        else if (dir.length() != 0) 
            s.push(dir);
    }
    if(s.empty())
    res = "/";
    while(!s.empty()){
        string t = s.top();
        res = "/"+t+res;
        s.pop();
    }
    return res;
}
