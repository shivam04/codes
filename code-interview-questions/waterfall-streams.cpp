#include <vector>

using namespace std;

vector<double> waterfallStreams(vector<vector<double>> array, int source) {
  vector<double> row = array[0];
	row[source] = -1;
	int n = array.size();
	int m = array[0].size();
	for(int i=1;i<n;i++) {
		vector<double> cRow = array[i];
		for(int j=0;j<m;j++) {
			double waterFlow = row[j];
			bool isWaterFlowing = waterFlow < 0;
			bool isBlock = cRow[j] == 1.0;
			if(!isWaterFlowing)
				continue;
			if(!isBlock) {
				cRow[j] += waterFlow;
				continue;
			}
			double waterSplit = waterFlow/2;
			int rI = j;
			while(rI+1 < m) {
				rI += 1;
				if(row[rI] == 1.0)
					break;
				if(cRow[rI] != 1) {
					cRow[rI] += waterSplit;
					break;
				}
			}
			
			int lI = j;
			while(lI-1>=0) {
				lI-=1;
				if(row[lI] == 1.0)
					break;
				if(cRow[lI] != 1) {
					cRow[lI] += waterSplit;
					break;
				}
			}
		}
		row = cRow;
	}
	vector<double> ans;
	for(double num: row) {
		if(num==0)
			ans.push_back(num);
		else
			ans.push_back(num*-100.0);
	}
  return ans;
}
