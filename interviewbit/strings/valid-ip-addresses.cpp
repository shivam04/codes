vector<string> Solution::restoreIpAddresses(string A) {
    int N = A.length();
    vector<string> v;
    if(N<=3)
    return v;
    if(N==4){
        string g= to_string(A[0]-48)+"."+to_string(A[1]-48)+"."+to_string(A[2]-48)+"."+to_string(A[3]-48);
        v.push_back(g);
        return v;
    }
    string f="",s="",t="",fo="";
    int i,j,k,l;
    for(i=N-1;i>=3;i--){
        f = A.substr(i,N-i);
        for(j=i-1;j>=2;j--){
            s = A.substr(j,i-j);
            for(k=j-1;k>=1;k--){
                t = A.substr(k,j-k);
                fo = A.substr(0,k);
                string g = fo+"."+t+"."+s+"."+f;
                string ip[4] = {fo,t,s,f};
                int flag = 0;
                for(int y=0;y<4;y++){
                    if(ip[y].length()>3 or stoi(ip[y])<0 or stoi(ip[y])>255){
                        flag = 1;
                        break;
                    }if(ip[y].length()>1 and stoi(ip[y])==0){
                        flag = 1;
                        break;
                    }if(ip[y].length()>1 and stoi(ip[y])!=0 and ip[y][0]=='0'){
                        flag = 1;
                        break;
                    }
                }
                if(!flag){
                    v.push_back(g);
                }
            }
        }
    }
    return v;
}
