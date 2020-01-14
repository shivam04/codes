string Solution::addBinary(string A, string B) {
    int carry = 0;
    int j = B.length()-1;
    int i = A.length()-1;
    string g="";
    //cout<<A.length()<<"\n";
   // cout<<isspace(A[i-1])<<"\n";
    while(i>=0 and isspace(A[i]))
    i--;
    while(j>=0 and B[j]==' ')
    j--;
    //cout<<i<<"\n";
    //cout<<A.substr(0,i+1)<<"\n";
    //cout<<B.substr(0,j+1)<<"\n";
    while(i>=0 and j>=0){
        //cout<<A[i]<<" "<<B[j]<<" "<<carry<<"\n";
        if(carry==1){
            if(A[i]=='0' and B[j]=='0'){
                g="1"+g;
                carry = 0;
            }else if((A[i]=='0' and B[j]=='1') or (A[i]=='1' and B[j]=='0')){
                g = "0"+g;
                carry = 1;
            }else{
                g = "1"+g;
                carry = 1;
            }
        }else{
            if(A[i]=='0' and B[j]=='0'){
                g="0"+g;
                carry=0;
            }else if((A[i]=='0' and B[j]=='1') or (A[i]=='1' and B[j]=='0')){
                g = "1"+g;
                carry = 0;
            }else{
                g = "0"+g;
                carry = 1;
            }
        }
       // cout<<g<<" "<<carry<<"\n";
        i--;
        j--;
    }
    while(i>=0){
        if(carry==1){
            if(A[i]=='1'){
                g = "0"+g;
                carry = 1;
            }
            else{
                g = "1"+g;
                carry = 0;
            }
        }else{
            g = A[i]+g;
            carry = 0;
        }
        i--;
    }
    while(j>=0){
        if(carry==1){
            if(B[j]=='1'){
                g = "0"+g;
                carry = 1;
            }
            else{
                g = "1"+g;
                carry = 0;
            }
        }else{
            g = B[j]+g;
            carry = 0;
        }
        j--;
    }
    if(carry==1)
    g = "1"+g;
    return g;
}
