class Solution {
public:
    int stoi(string s) {
        int n = 0;
        bool isNeg = s[0]=='-';
        if(isNeg) {
            s = s.substr(1);
        }
        for(char c: s) {
            int p = c-48;
            n = n*10+p;
        }
        if(isNeg) {
            n *= -1;
        }
        return n;
    }
    int evalRPN(vector<string>& str) {
        stack<int> s;
        for(string ss: str) {
            //cout<<ss<<"\n";
            int a,b;
            char cc = ss[0];
            if(ss.length()>=2) {
                cc = '@';
            }
            switch(cc) {
                case '+':
                    b = s.top(); s.pop();
                    a = s.top(); s.pop();
                    s.push(a+b);
                    //cout<<a<<" "<<b<<" "<<s.top()<<"\n";
                    break;
                case '-':
                    b = s.top(); s.pop();
                    a = s.top(); s.pop();
                    s.push(a-b);
                    //cout<<a<<" "<<b<<" "<<s.top()<<"\n";
                    break;
                case '*':
                    b = s.top(); s.pop();
                    a = s.top(); s.pop();
                    s.push(a*b);
                    //cout<<a<<" "<<b<<" "<<s.top()<<"\n";
                    break;
                case '/':
                    b = s.top(); s.pop();
                    a = s.top(); s.pop();
                    s.push(a/b);
                    //cout<<a<<" "<<b<<" "<<s.top()<<"\n";
                    break;
                default:
                    int c = stoi(ss);
                    s.push(c);
                    break;
            }
        }
        return s.top();
    }
};