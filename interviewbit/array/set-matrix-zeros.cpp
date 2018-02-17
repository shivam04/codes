void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m = A.size();
    int n = A[0].size();
    bool R = false, C = false;

    for(int j=0;j<n;j++){
         if(A[0][j]==0 ){
             R=true;
             break;
         }
     }
     
     for(int j=0;j<m;j++){
         if(A[j][0]==0){
             C=true;
             break;
             
         }
     }
     for(int i =1;i<m;i++){
         for (int j=1;j<n;j++){
            if(A[i][j]==0){
                A[i][0]=0;
                A[0][j]=0;
            }
         }
     }
     for(int i=1;i<m;i++){
         for(int j=1;j<n;j++){
             if(A[i][0]==0 || A[0][j]==0){
                 A[i][j]=0;
             }
         }
     }
     if(R){
         for(int i=0;i<n;i++){
             A[0][i]=0;
         }
     }
 
     if(C){
         for(int i=0;i<m;i++){
             A[i][0]=0;
         }
     }
    
}
