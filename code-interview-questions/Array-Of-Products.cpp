#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> array) {
  int p = 1;
	int zc = 0;
	for(int n: array) {
		if(n!=0)
			p*=n;
		zc += (n==0);
	}
	vector<int> ans;
	if(zc>1) {
		for(int n: array) {
			ans.push_back(0);
		}
	}
	else {
		for(int n: array) {
			if(n!=0)
				ans.push_back((p/n)* (zc==1?0:1));
			else
				ans.push_back(p);
		}
	}
  return ans;
}
