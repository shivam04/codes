/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


// The task is to complete this function
int getId(int M[MAX][MAX], int n)
{
    stack<int> s;
    for(int i=0;i<n;i++){
        s.push(i);
    }
    int A = s.top();
    s.pop();
    int B = s.top();
    s.pop();
    while(s.size()>1){
        if(M[A][B]){
            A = s.top();
            s.pop();
        }else{
            B = s.top();
            s.pop();
        }
    }
    int C = s.top();
    s.pop();
    if(M[C][B])
    C = B;
    if(M[C][A])
    C = A;
    for(int k=0;k<n;k++){
        if(k!=C and (M[C][k] or !M[k][C]))
        return -1;
    }
    return C;
}