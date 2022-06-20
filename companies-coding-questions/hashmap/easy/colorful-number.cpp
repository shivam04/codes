int Solution::colorful(int A) {
    unordered_map<long,int> mp;
    vector<int> d;
    int temp = A;
    while(temp) {
        d.push_back(temp%10);
        temp/=10;
    }
    reverse(d.begin(), d.end());
    for(int i=0;i<d.size();i++) {
        long ans = 1;
        for(int j=i;j<d.size();j++) {
            ans*=((long)d[j]);
            if(mp.find(ans)!=mp.end())
                return 0;
            mp[ans] = 1;
        }
    }
    return 1;
}
