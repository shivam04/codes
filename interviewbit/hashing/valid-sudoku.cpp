#define f first
#define s second
int Solution::isValidSudoku(const vector<string> &A) {
    for(int i=0;i<9;i++){
        unordered_map<int,int> mp;
        for(int j=0;j<9;j++){
            if(A[i][j]!='.' and mp.find(A[i][j]-48)!=mp.end()){
                return 0;
            }
            if(A[i][j]!='.')
            mp[A[i][j]-48] = 1;
        }
    }
    for(int i=0;i<9;i++){
        unordered_map<int,int> mp;
        for(int j=0;j<9;j++){
            if(A[j][i]!='.' and mp.find(A[j][i]-48)!=mp.end()){
                return 0;
            }
            if(A[j][i]!='.')
            mp[A[j][i]-48] = 1;
        }
    }
    char arr[9][3][3];
    for(int i=0;i<9;i+=3){
        for(int j=0;j<9;j++){
            for(int k=0;k<3;k++){
                arr[j/3+i][k][j%3] = A[k+i][j];
            }
        }
    }
    
    for(int i=0;i<9;i++){
        unordered_map<int,int> mp;
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(arr[i][j][k]!='.' and mp.find(arr[i][j][k]-48)!=mp.end()){
                    return 0;
                }
                if(arr[i][j][k]!='.')
                mp[arr[i][j][k]-48] = 1;
            }
        }
    }
    return 1;
}
