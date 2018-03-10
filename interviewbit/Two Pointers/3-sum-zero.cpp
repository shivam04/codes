vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(A.begin(),A.end());
    int n = A.size();
    vector<vector<int> > ans;
    for(int i=0;i<n-1;i++){
        int l = i+1;
        int r = n-1;
        while(l<r){
            vector<int> k;
            if(A[i]+A[l]+A[r]==0){
                k.push_back(A[i]);
                k.push_back(A[l]);
                k.push_back(A[r]);
                ans.push_back(k);
                //cout<<A[i]<<" "<<A[l]<<" "<<A[r]<<"\n";
                k.erase(k.begin(),k.end());
                while(A[l] == A[l+1]){
                    l++;
                    if(l == A.size()){
                        break;
                    }
                }
                l++;
                //r--;
            }else if(A[i]+A[l]+A[r]<0){
                while(A[l] == A[l+1]){
                    l++;
                    if(l == A.size()){
                        break;
                    }
                }
                l++;
            }else{
                while(A[r] == A[r-1]){
                    r--;
                    if(r == 0){
                        break;
                    }
                }
                r--;
            }
        }
        while(A[i+1] == A[i]){
            i++;
            if(i == A.size()-1){
                return ans;
            }
        }
        
    }
    return ans;
}
