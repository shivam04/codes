#include <bits/stdc++.h>
using namespace std;

int ans(vector<string> words, string w[], int l) {
	int cnt = 0;
	int anss = 0;
	for(int i=0;i<l;i++) {
		int cnt = 0;
		for(int j=0;j<w[i].length();j++) {
		//	fout<<w[i][j]<<" "<<words[j]<<"\n";
			for(int k=0;k<words[j].length();k++) {
				if(words[j][k]==w[i][j]) {
					cnt++;
					break;
				}
			}
		}
	//	fout<<cnt<<"\n";
		if(cnt == w[i].length()) {
			anss++;
		}
	}
	return anss;
}

int main() {
	fstream fout,fin;
    fin.open("A-large-practice.txt",ios::in);
    fout.open("A-large-practice-output.txt",ios::out);
	int l,d,n;
	fin>>l>>d>>n;
	string w[d+1];
	for(int i=0;i<d;i++) {
		fin>>w[i];
	}
	for(int i=1;i<=n;i++) {
		string m;
		fin>>m;
		string temp = "";
		vector<string> words;
		bool f = false;
		for(int j=0;j<m.length();j++) {
			if(m[j]=='(') {
				f = true;
			}
			else if(m[j]==')') {
				f = false;
				words.push_back(temp);
				temp = "";
			} else {
				if(f) {
					temp+=m[j];
				} else {
					string h = "";
					h = h + m[j];
					words.push_back(h);
				}
			}
		}
		fout<<"Case #"<<i<<": "<<ans(words, w,d)<<"\n";
	}
	return 0;
}