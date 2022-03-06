#include<sstream>
using namespace std;

string reverseWordsInString(string str) {
	if(str == " ")
		return str;
  vector<string> words;
	istringstream iss(str);
	string token;
	while(getline(iss, token, ' ')) {
		words.push_back(token);
	}
	string ans = "";
	if(str[str.length()-1]==' ')
		ans = " ";
	for(int i=words.size()-1;i>=0;i--) {
		cout<<words[i];
		ans = ans + words[i] + " ";
	}
  return ans.substr(0, ans.length()-1);
}
