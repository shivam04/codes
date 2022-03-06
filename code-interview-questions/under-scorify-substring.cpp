using namespace std;
vector<int> computeLPSArray(string str) {
	int n = str.size();
	vector<int> lps(n);
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while(i<n) {
		if(str[i] == str[len]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			if (len != 0) {
				len = lps[len - 1];
			} else {
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}
string underscorifySubstring(string str, string subStr) {
  vector<int> lps = computeLPSArray(str);
	int n = str.length();
  int p = subStr.length();
	int i = 0;
	int j = 0;
	vector<int> fII;
	while (i < n) {
		if(subStr[j]==str[i]) {
			j++;
			i++;
		}
		if(j==p) {
			fII.push_back(i-j);
			j = lps[j - 1];
		}else if (i < n && subStr[j] != str[i]) {
			if(j!=0)
				j = lps[j-1];
			else
				i++;
		}
	}
	fII.push_back(n+1);
	string ans = "";
	i = 0;
	int eL = fII[0];
	ans = str.substr(0, eL);
	while(i<fII.size()-1) {
		eL = min(p, fII[i+1] - fII[i]);
		if(i>0 and fII[i]-fII[i-1]>p or i==0) {
			ans = ans + "_";
		}
		ans = ans + str.substr(fII[i], eL);
		if(eL==p and fII[i] + p < fII[i+1]) {
			ans = ans + "_" + str.substr(fII[i] + p, fII[i+1]-fII[i]-p);
		}
		i++;
	}
  return ans;
}
