#include<bits/stdc++.h>
using namespace std;

int kjump (vector<int> v, int K) {
    if(v.size()==0) {
        return 0;
    }
    std::vector<int> tail(v.size(), 0);  
    int length = 1;
    tail[0] = v[0];
    for(int i=1;i<v.size();i++) {
        auto b = tail.begin(), e = tail.begin() + length; 
        auto it = upper_bound(b, e, (v[i]-K));
        if(it==tail.begin() + length) {
            tail[length++] = v[i];  
        } else if(*it > v[i]) {
            *it = v[i];
        }
    }
    return length;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int K;
    cin >> K;
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i_A=0; i_A<N; i_A++)
    {
    	cin >> A[i_A];
    }

    int out_;
    out_ = kjump(A, K);
    cout << out_;
}