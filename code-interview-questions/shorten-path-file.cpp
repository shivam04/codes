#include<stack>
#include<sstream>
using namespace std;

string shortenPath(string path) {
  bool startWithSlash = path[0] == '/';
	vector<string> tokens;
	string token;
	vector<string> filteredTokens;
	istringstream iss(path);
	while(getline(iss, token, '/')) {
		tokens.push_back(token);
	}
	copy_if(tokens.begin(), tokens.end(), back_inserter(filteredTokens), 
				 [](string token) {
					 return token.length() and token != ".";
				 });
	stack<string> s;
	if(startWithSlash)
		s.push("");
	for(string token: filteredTokens) {
		if(token=="..") {
			if(s.empty() or s.top()=="..")
				s.push(token);
			else if(s.top() != "")
				s.pop();
		} else {
			s.push(token);
		}
	}
	string res = "";
	while(!s.empty()) {
		string dir = s.top();
		s.pop();
		if(s.empty())
			res = dir + res;
		else
			res = "/" + dir + res;
	}
  return res == "" ? "/" : res;
}
