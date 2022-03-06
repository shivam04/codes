#include <vector>
using namespace std;

unordered_map<int,vector<char>> mp;
void ans(string phoneNumber, vector<string> &answer, int sI, string combination) {
	if(sI==phoneNumber.size()) {
		answer.push_back(combination);
		return;
	}
	for(int j=0;j<mp[phoneNumber[sI]-48].size();j++) {
		ans(phoneNumber, answer, sI+1, combination+mp[phoneNumber[sI]-48][j]);
	}
}

vector<string> phoneNumberMnemonics(string phoneNumber) {
  vector<char> l;
	l.push_back('0');
	mp[0] = l;
	l.clear();
	l.push_back('1');
	mp[1] = l;
	l.clear();
	l.push_back('a');
	l.push_back('b');
	l.push_back('c');
	mp[2] = l;
	l.clear();
	l.push_back('d');
	l.push_back('e');
	l.push_back('f');
	mp[3] = l;
	l.clear();
	l.push_back('g');
	l.push_back('h');
	l.push_back('i');
	mp[4] = l;
	l.clear();
	l.push_back('j');
	l.push_back('k');
	l.push_back('l');
	mp[5] = l;
	l.clear();
	l.push_back('m');
	l.push_back('n');
	l.push_back('o');
	mp[6] = l;
	l.clear();
	l.push_back('p');
	l.push_back('q');
	l.push_back('r');
	l.push_back('s');
	mp[7] = l;
	l.clear();
	l.push_back('t');
	l.push_back('u');
	l.push_back('v');
	mp[8] = l;
	l.clear();
	l.push_back('w');
	l.push_back('x');
	l.push_back('y');
	l.push_back('z');
	mp[9] = l;
	l.clear();
	vector<string> answer;
	string combination = "";
	ans(phoneNumber,answer, 0, combination);
  return answer;
}
