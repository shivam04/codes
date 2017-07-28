#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
const int maxn = 100005;
LL A[maxn], sum[maxn];
bool visited[maxn];
int main() {
	int n, k, d, last = -1, res = 0;
	LL ksum = 0;
	scanf("%d %d %d", &n, &k, &d);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", A + i);
	}
	for (int i = 1; i <= n; ) {
		if (A[i]) last = i;
		sum[i] = sum[i - 1] + A[i];
		if (i >= k) {
			ksum = sum[i] - sum[i - k];
			if (ksum < d) {
				if (last == -1 || visited[last]) {
					printf("-1");
					return 0;
				}
				visited[last] = true;
				++res;
				for (int j = last; j < min(last + k, n + 1); ++j) {
					A[j] = min(A[j] * maxn, (long long)maxn);
				}
				i = last;
			} else ++i;
		} else ++i;
	}
	printf("%d", res);
	return 0;
}