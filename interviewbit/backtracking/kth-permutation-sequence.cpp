string Solution::getPermutation(int A, int B) {
    if(A==0)
    return "";
    if( A==1)
    return "1";
    string p="";
    int c=1;
    for(int i=1;i<=A;i++)
    p = p + to_string(i);
    do{
       if(c==B)
       return p;
       c++;
    }while (next_permutation(p.begin(), p.end()));
}
