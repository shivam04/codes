#include <vector>
using namespace std;

bool isValid(string s) {
	int a = stoi(s);
	cout<<s<<" "<<a<<"\n";
	if(a>255)
		return false;
	return s.length() == to_string(a).length();
}

vector<string> validIPAddresses(string str) {
	vector<string> ans;
	for(int i=1;i<min((int)str.length(), 4); i++) {
		string firstPart = str.substr(0, i);
		if(!isValid(firstPart)) {
			continue;
		}
		for(int j=i+1;j<i+min((int)str.length()-i,4);j++) {
			string secondPart = str.substr(i, j-i);
			if(!isValid(secondPart)) {
				continue;
			}
			for(int k=j+1;k<j+min((int)str.length()-j,4);k++) {
				string thirdPart = str.substr(j, k-j);
				string fourthPart = str.substr(k);
				if(!isValid(thirdPart) or !isValid(fourthPart)) {
					continue;
				}
				ans.push_back(firstPart+"."+secondPart+"."+thirdPart+"."+fourthPart);
			}
		}
	}
  return ans;
}
