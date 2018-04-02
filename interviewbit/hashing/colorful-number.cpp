int Solution::colorful(int A) {
    int n = A;
    unordered_map<int,int> mp;
    int c = 0;
    vector<int> v;
    while(n){
        c++;
        int p = n%10;
        if(mp[p]==1)
        return 0;
        mp[p] = 1;
        v.push_back(p);
        n/=10;
    }
    for(int i=2;i<=c;i++){
        for(int j=0;j<v.size()-i+1;j++){
            int y = 1;
            for(int k=j;k<j+i;k++){
                y*=v[k];
            }
            if(mp[y]==1)
            return 0;
            mp[y]=1;
        }
    }
    return 1;
}
