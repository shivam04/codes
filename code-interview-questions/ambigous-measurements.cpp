#include <vector>
using namespace std;
unordered_map<string,bool> mp;
bool ambiguousMeasurementsUtil(vector<vector<int>> measuringCups, int n, int low, int high,
															int mL, int mH) {
	string key = to_string(mL) + ":" + to_string(mH);
	if(mL>=low and mH>=high) {
		return false;
	}
	if(mp.find(key) != mp.end())
		return mp[key];
	bool ans = false;
	for(auto cup: measuringCups) {
		if(low <= cup[0] + mL  and cup[1]+mH <= high) {
			ans = true;
			break;
		}
		ans = ambiguousMeasurementsUtil(measuringCups, n, low, high, cup[0]+mL, cup[1]+mH);
		if(ans)
			break;
	}
	return mp[key] = ans;
}

bool ambiguousMeasurements(vector<vector<int>> measuringCups, int low,
                           int high) {
	mp.clear();
	int n = measuringCups.size();
	return ambiguousMeasurementsUtil(measuringCups, n, low, high, 0 , 0);
}
