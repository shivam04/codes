using namespace std;
int getNextIdx(int cI, vector<int> array) {
	int j = array[cI];
	int nI = (cI + j)%(int)array.size();
	return nI>=0 ? nI : nI + array.size();
}
bool hasSingleCycle(vector<int> array) {
  int nV = 0;
	int cI = 0;
	while(nV < array.size()) {
		if(nV>0 and cI == 0)
			return false;
		nV++;
		cI = getNextIdx(cI, array);
	}
  return cI==0;
}
