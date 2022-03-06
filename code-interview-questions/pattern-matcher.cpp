#include <bits/stdc++.h>
using namespace std;

vector<char> getNewPattern(string pattern) {
	vector<char> patternL(pattern.begin(), pattern.end());
	if(pattern[0]=='x')
		return patternL;
	transform(patternL.begin(), patternL.end(), 
						patternL.begin(), 
						[](char c) -> char {return c=='y' ? 'x' : 'y';});
	return patternL;
}

int getCount(vector<char> nPattern, unordered_map<char,int> *counts) {
	int fYp = -1;
	for(int i=0;i<nPattern.size();i++) {
		char c = nPattern[i];
		counts->at(c)++;
		if(c=='y' and fYp == -1)
			fYp = i;
	}
	return fYp;
}

vector<string> patternMatcher(string pattern, string str) {
  int n = str.length();
	int m = pattern.length();
	if(m>n)
		return vector<string> {};
	vector<char> nPattern = getNewPattern(pattern);
	bool isChanging = (pattern[0] != nPattern[0]);
	unordered_map<char,int> counts({{'x', 0}, {'y', 0}});
	int firstYPos = getCount(nPattern, &counts);
	if(counts['y'] != 0) {
		for(int lenOfX = 1; lenOfX<str.length();lenOfX++) {
			double lenOfY = ((double)str.length() - (double)lenOfX*(double)counts['x'])/
				(double)counts['y'];
			if(lenOfY <= 0 or fmod(lenOfY, 1) != 0)
				continue;
			double YIdx = firstYPos*lenOfX;
			string x = str.substr(0, lenOfX);
			string y = str.substr(YIdx, lenOfY);
			vector<string> pM(nPattern.size(), "");
			transform(nPattern.begin(), nPattern.end(), pM.begin(), 
								[x,y](char c) -> string {return c=='x' ? x:y;});
			if(str==accumulate(pM.begin(),pM.end(), string("")))
				return !isChanging ? vector<string> {x, y} : vector<string> {y, x};
		}
	} else {
		double lenOfX = n/counts['x'];
		if(fmod(lenOfX, 1) == 0) {
			string x = str.substr(0, lenOfX);
			vector<string> pM(nPattern.size(), "");
			transform(nPattern.begin(), nPattern.end(), pM.begin(), 
								[x](char c) -> string {return x;});
			if(str == accumulate(pM.begin(), pM.end(), string(""))) {
				return !isChanging ? vector<string> {x, ""} : vector<string> {"", x};
			}
		}
	}
  return vector<string> {};
}
