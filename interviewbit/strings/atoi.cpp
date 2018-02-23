int Solution::atoi(const string A) {
    int N = A.length();
    string num1="";
    int num = 0;
    int i=0;
    int c=0;
    int  flag = 0;
    while(i<N and (A[i]<48 || A[i]>57)){
        if(A[i]!=' ')
        flag = 1;
        i++;
        c++;
    }
    if(c==1 and (A[0]!='+' and A[0]!='-' and flag!=0 )){
        return 0;
    }else if(c==1){
        flag=0;
    }
    if(flag)
    return 0;
    while(i<N and A[i]=='0')
    i++;
    while(i<N and A[i]>=48 and A[i]<=57 and A[i]){
        num1 = num1+A[i];
        num = num*10+(A[i]-48);
        i++;
    }
    //cout<<num1<<" "<<to_string(INT_MAX)<<"\n";
    //cout<<(num1>to_string(INT_MAX))<<"\n";
    if(c==1){
        if(A[0]==' '){
            if(num1.length()>10)
            return INT_MAX;
            if(num1>to_string(INT_MAX) and num1.length()>=10)
            return INT_MAX;
            return num;
        }
        
        else if(A[0]=='-'){
            if(num1.length()>10)
            return INT_MIN;
            if(num1>to_string(INT_MAX) and num1.length()>=10)
            return INT_MIN;
            return -1*num;
        }
        else{
            if(num1.length()>10)
            return INT_MAX;
            if(num1>to_string(INT_MAX) and num1.length()>=10)
            return INT_MAX;
            return num;
        }
    }
    if(num1.length()>10)
            return INT_MAX;
    if(num1>to_string(INT_MAX) and num1.length()>=10)
    return INT_MAX;
    return num;
}
