vector<int> Solution::lszero(vector<int> &A) {
    int n = A.size();
    int prefix[n];
    prefix[0] = A[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1]+A[i];
    }
    int max_len = -1;
    int max_i=-1;
    for(int i=0;i<n;i++){
        if(prefix[i]==0){
            if(max_len<(i+1)){
                max_len = i+1;
                max_i = i;
            }
        }
    }
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        if(mp.find(prefix[i])==mp.end()){
            mp[prefix[i]] = i;
        }else{
            if(max_len<(i-mp[prefix[i]])){
                max_len = i-mp[prefix[i]];
                max_i = i;
            }
        }
    }
    
    vector<int> ans;
    if(max_i==-1)
    return ans;
    for(int k=max_i-max_len+1;k<=max_i;k++){
       ans.push_back(A[k]);
    }
    return ans;
}
