#include <bits/stdc++.h>
using namespace std;

struct train{
	int dh, dm, ah, am, fl, done;
};

bool cmp(struct train p, struct train q)
{
	return ((p.dh<q.dh) or (p.dh==q.dh and p.dm<q.dm)) or (p.dh==q.dh and p.dm==q.dm and p.ah<q.ah) or (p.dh==q.dh and p.dm==q.dm and p.ah==q.ah and p.am<q.am);
	
}


int main() {
	int t;
	cin>>t;
	for(int k=1;k<=t;k++) {
		int T;
		cin>>T;
		int na,nb;
		cin>>na>>nb;
		struct train arr[na+nb+1];
		for(int i=0;i<na;i++) {
			scanf("%d:%d %d:%d", &arr[i].dh, &arr[i].dm, &arr[i].ah, &arr[i].am);
			arr[i].fl=arr[i].done = 0;
		}
		for(int i=na;i<na+nb;i++) {
			scanf("%d:%d %d:%d", &arr[i].dh, &arr[i].dm, &arr[i].ah, &arr[i].am);
			arr[i].fl=1;
			arr[i].done = 0;
		}
		if(na==0 || nb==0) {
			printf("Case #%d: %d %d\n", k, na, nb);
			continue;
		}
		sort(arr, arr+na+nb, cmp);
		int ans[2];
		ans[0]=ans[1]=0;
		int fl,th,tm;
		for(int i=0;i<na+nb;i++) {
			if(arr[i].done)
				continue;
			arr[i].done = 1;
			ans[arr[i].fl]++;
			fl = arr[i].fl;
			th = arr[i].ah;
			tm = arr[i].am+T;
			th = th + tm/60;
			tm = tm%60;
			for(int j=i+1; j<na+nb; j++) {
				if(arr[j].done || arr[j].fl==fl)
					continue;
				if(th < arr[j].dh || (th==arr[j].dh and tm<=arr[j].dm)) {
					arr[j].done = 1;
					th = arr[j].ah;
					tm = arr[j].am + T;
					th = th + tm/60;
					tm = tm%60;
					fl = 1 - fl;
				}
			}
		}
		cout<<"Case #"<<k<<": "<<ans[0]<<" "<<ans[1]<<"\n";	
		
	}
	return 0;
}