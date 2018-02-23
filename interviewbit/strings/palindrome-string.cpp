int Solution::isPalindrome(string A) {
    string s="";
    for(int i=0;i<A.size();i++){
        if(isalnum(A[i]))
        s+=tolower(A[i]);
    }
    int len = s.length();
    for(int i=0;i<=len/2;i++){
        if(s[i]!=s[len-i-1]){
            return 0;
        }
    }
    return 1;
}

