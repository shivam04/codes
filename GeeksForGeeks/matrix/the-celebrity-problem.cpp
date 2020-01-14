/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


// The task is to complete this function
int getId(int M[MAX][MAX], int n)
{
    int i=0;
    int j = n-1;
    while(i<j){
        if(M[i][j])
        i++;
        else
        j--;
    }
    for(int k=0;k<n;k++){
        if(k!=i and (M[i][k] or !M[k][i]))
        return -1;
    }
    return i;
}