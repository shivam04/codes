#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> a(n, 0), b(n, 0);
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	for(int i=0;i<n;i++) {
		cin>>b[i];
	}
	
	int mini = *min_element(a.begin(), a.end());
	int cnt = 0;
	int i = 0;
	while(i<n) {
		if (a[i]>=b[i]) {
			while(a[i] > mini) {
				a[i]-=b[i];
				cnt++;
			}
		} if (a[i] < mini) {
			mini = a[i];
			i = 0;
		} if (a[i] != mini) {
			cnt = -1;
			break;
		}
		i++;
	}
	cout<<cnt<<"\n";
}
