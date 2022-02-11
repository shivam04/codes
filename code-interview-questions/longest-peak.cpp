using namespace std;

int longestPeak(vector<int> array) {
  int maxL = 0;
	int n = array.size();
	int i = 1;
	while(i<n-1) {
		bool isPeak = (array[i-1] < array[i] && array[i] > array[i+1]);
		if(!isPeak) {
			i++;
			continue;
		}
		int li = i-2;
		while(li>=0 and array[li] < array[li+1]) {
			li-=1;
		}
		int ri = i+2;
		while(ri<n and array[ri] < array[ri-1]) {
			ri+=1;
		}
		int cl = (ri-li-1);
		maxL = max(maxL, cl);
		i = ri;
	}
  return maxL;
}
