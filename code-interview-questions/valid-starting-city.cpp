#include <vector>
using namespace std;

int validStartingCity(vector<int> distances, vector<int> fuel, int mpg) {
	int n = distances.size();
	int mR = 0;
	int sI = 0;
	int mRS = 0;
	for(int i=1;i<n;i++) {
		int d = distances[i-1];
		int f = fuel[i-1];
		mR += f*mpg - d;
		if(mR < mRS) {
			mRS = mR;
			sI = i;
		}
	}
  return sI;
}
