#define Mod 1000003
long long fact (int n) {
    if (n == 0 || n == 1)
        return 1;
    long long ans = 1;
    while (n > 1) {
        ans = (ans * n) % Mod;
        n--;
    }
    return ans;
}
long long modPow (long long a, long long n) {
    long long ans = 1;
    while (n > 0) {  
        if (n & 1)
            ans = (ans * a) % Mod;
        a = (a * a) % Mod;
        n >>= 1;
    }
    return ans;
}

int Solution::findRank(string A) {
    int n = A.size();
    long long ans = 1, dup, lessN, cnt;
    for(int i=0;i<n;i++) {
        lessN = 0;
        for(int j=i+1;j<n;j++) {
            if(A[j]<A[i])
                lessN++;
        }
        map<char,long long> mp;
        for(int j=i;j<n;j++) {
            mp[A[j]]++;
        }
        dup = 1;
        cnt = (fact(n-i-1)%Mod*lessN)%Mod;
        for(auto it:mp) {
            dup = (dup*fact(it.second))%Mod;
        }
        dup = modPow(dup, Mod - 2);
        cnt = (cnt * dup) % Mod;
        ans = (ans + cnt) % Mod;
    }
    return ans;
}



