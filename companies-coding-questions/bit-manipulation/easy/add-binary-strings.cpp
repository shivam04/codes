string Solution::addBinary(string A, string B) {
    int i = A.size();
    int j = B.size();
    if(i>j) {
        int d = i-j;
        for(int k=0;k<d;k++) {
            B = '0' + B;
        }
    } else {
        int d = j-i;
        for(int k=0;k<d;k++) {
            A = '0' + A;
        }
    }
    i = A.size()-1;
    j = B.size()-1;
    string temp = "";
    char carry = '0';
    while(i>=0 and j>=0) {
        if(A[i]=='0' and B[j]=='1') {
            if(carry=='1') {
                temp = '0' + temp;
                carry = '1';
            } else {
                temp = '1' + temp;
                carry = '0';
            }
        }
        else if (A[i]=='1' and B[j]=='0') {
            if(carry=='1') {
                temp = '0' + temp;
                carry = '1';
            } else {
                temp = '1' + temp;
                carry = '0';
            }
        }
        else if (A[i]=='1' and B[j]=='1') {
            if(carry=='1') {
                temp = '1' + temp;
                carry = '1';
            } else {
                temp = '0' + temp;
                carry = '1';
            }
        }
        else {
            if(carry=='1') {
                temp = '1' + temp;
                carry = '0';
            } else {
                temp = '0' + temp;
                carry = '0';
            }
        }
        i--;
        j--;
    }
    if(carry=='1')
        temp = '1' + temp;
    return temp;
}
