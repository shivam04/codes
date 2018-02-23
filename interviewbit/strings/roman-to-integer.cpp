int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
 
    return -1;
}
int Solution::romanToInt(string A) {
    int N = A.length();
    int result = 0;
    for(int i=0;i<N;i++){
        int s1 = value(A[i]);
        if(i+1<N){
            int s2 = value(A[i+1]);
            if(s1>=s2){
                result = result+s1;
            }else{
                result = result + s2-s1;
                i++;
            }
        }else{
            result = result+s1;
            i++;
        }
    }
    return result;
}
