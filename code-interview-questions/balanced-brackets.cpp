#include<stack>
using namespace std;

bool balancedBrackets(string str) {
 	stack<char> s;
	for(char c: str) {
		if(c=='(' || c=='{' || c=='[') {
			s.push(c);
		} else if(c==')' || c=='}' || c==']'){
			if(s.empty())
				return false;
			if(c==')' and s.top()=='(')
				s.pop();
			else if(c=='}' and s.top()=='{')
				s.pop();
			else if(c==']' and s.top()=='[')
				s.pop();
			else
				return false;
		}
	}
  return s.empty();
}
