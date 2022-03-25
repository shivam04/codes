using namespace std;
void update(int x, int delta, int BIT[], int n) {
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
}
int query(int x, int BIT[], int n) {
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}
void convert(vector<int> &array, int n) {
	vector<int> temp;
	temp = array;
	sort(temp.begin(), temp.end());
	for(int i=0;i<n;i++)
		array[i] = lower_bound(temp.begin(), temp.end(), array[i]) - temp.begin() + 1;
}
vector<int> rightSmallerThan(vector<int> array) {
	int n = array.size();
	vector<int> ans(n,0);
	int BIT[n+2];
	memset(BIT,0,sizeof(BIT));
	convert(array,n);
	for(int i=n-1;i>=0;i--) {
		ans[i] = query(array[i]-1,BIT,n);
		update(array[i], 1, BIT, n);
	}
  return ans;
}
