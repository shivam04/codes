#include<bits/stdc++.h>
using namespace std;
int bfs(int n, int m, int num) {
    int count = 0;
    queue<int> q;
    q.push(num);
    while(!q.empty()) {
        int stepNum = q.front();
        q.pop();
        if(stepNum >= n and stepNum <= m) {
            count++;
        }
        if (num == 0 || stepNum > m)
            continue;
        int lastDigit = stepNum % 10;
        int stepNumA = stepNum * 10 + (lastDigit - 1);
        int stepNumB = stepNum * 10 + (lastDigit + 1);
        if (lastDigit == 0)
            q.push(stepNumB);
        else if (lastDigit == 9)
            q.push(stepNumA);
        else{
            q.push(stepNumA);
            q.push(stepNumB);
        }
    }
    return count;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n,m;
	    cin>>n>>m;
	    int count = 0;
	    for(int i=0;i<=9;i++) {
	        count += bfs(n,m,i);
	    }
	    cout<<count<<"\n";
	}
	return 0;
}