/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Read only ( DON'T MODIFY ) Integer array
 * @input n2 : Integer array's ( B ) length
 * 
 * @Output Double
 */
int max(int a,int b){
    return a>=b?a:b;
}
int min(int a,int b){
    return a<=b?a:b;
}
double mo3i(int a,int b,int c){
    return a + b + c - max(a, max(b, c))- min(a, min(b, c));
}
double mo4i(int a,int b,int c,int d){
    int Max = max( a, max( b, max( c, d ) ) );
    int Min = min( a, min( b, min( c, d ) ) );
    return ( a + b + c + d - Max - Min ) / 2.0;
}
double find_median(int *A, int n,int *B,int m){
    if(n==0){
        if(m&1)
            return (double)B[m/2];
        return (double)(B[m/2-1]+B[m/2])/2.0; 
    }
    /*if(m==0){
       if(n&1)
            return (double)A[n/2];
        return (double)(A[n/2-1]+A[n/2])/2; 
    }*/
    if(n==1 && m==1)
    return (double)(A[0]+B[0])/2.0;
    if(n==1){
        if(m%2){
            double k = mo3i(A[0],B[m/2 - 1],B[m/2 + 1]);
            return (double)(k+B[m/2])/2.0;
        }else{
            return (double)mo3i(B[m/2],B[m/2 - 1],A[0]);
        }
    }
    /*if(m==1){
        if(n%2){
            int k = mo3i(B[0],A[n/2-1],A[n/2+1]);
            return (double)(k+A[n/2])/2.0;
        }else{
            return (double)mo3i(A[n/2],A[n/2-1],B[0]);
        }
    }*/
    if(n==2 && m==2){
        return mo4i(A[0],A[1],B[0],B[1]);
    }
    if(n==2){
        if(m&1){
            return mo3i(B[m/2],max(A[0], B[m/2 - 1]),min(A[1], B[m/2 + 1]));
        }else{
            return mo4i(B[m/2],B[m/2-1],max(A[0],B[m/2 - 2]),min(A[1],B[m/2 + 1]));
        }
    }
    /*if(m==2){
        if(n&1){
            return mo3i(A[n/2],max(B[0], A[n/2 - 1]),min(B[1], A[n/2 + 1]));
        }else{
            return mo4i(A[n/2],A[n/2-1],max(B[0],A[n/2-2]),min(B[1],A[n/2+1]));
        }
    }*/
    int a = (n - 1)/2;
    int b = (m - 1)/2;
    if(A[a]<=B[b])
        return find_median(A+a,n/2+1,B,m-a);
    return find_median(A,n/2+1,B+a,m-a);
}
double findMedianSortedArrays(const int* A, int n1, const int* B, int n2) {
    if(n1<=n2)
        return find_median(A,n1,B,n2);
    return find_median(B,n2,A,n1);
}
