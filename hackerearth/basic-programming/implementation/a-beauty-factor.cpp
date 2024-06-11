#include <bits/stdc++.h>
using namespace std;

int cntDistinct(string str){
    map<char, int> count;
    for(int i = 0; i < str.length(); i++){
        count[str[i]]++;
    }
    return count.size();
}

int checkBeauty(string start) {
	int s = 0;
	for(char c: start) {
		s += (c-48);
	}

	if (to_string(s).length() > 1) {
		return checkBeauty(to_string(s));
	}
	return s;
}

int main() {
	int b,k;
	cin>>b>>k;
	if (k==9) {
		if (b==9) {
			cout<<"123456789\n";
		} else {
			cout<<"-1\n";
		}
	} else {
		string tailZero = "";
		for (int i=0;i<k-1;i++) {
			tailZero += "0";
		}
		string start = "1" + tailZero;
		while(1==1) {
			if (start.find("0") != string::npos) {
				int n = stoi(start);
				n += 1;
				start = to_string(n);
				continue;
			} 

			if (cntDistinct(start) != start.length()) {
				int n = stoi(start);
				n += 1;
				start = to_string(n);
				continue;
			}

			int beautyfactor = checkBeauty(start);

			if (beautyfactor == b) {
				cout<<start<<"\n";
				break;
			}

			int n = stoi(start);
			n += 1;
			start = to_string(n);
			if (start.length() > k) {
				cout<<-1<<"\n";
				break;
			}
		}
	}
}