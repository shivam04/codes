//tle
class Solution {
public:
    bool isValidString(string str) { 
        int cnt = 0; 
        for (int i = 0; i < str.length(); i++) { 
            if (str[i] == '(') 
                cnt++; 
            else if (str[i] == ')') 
                cnt--; 
            if (cnt < 0) 
                return false; 
        } 
        return (cnt == 0); 
    } 
    string minRemoveToMakeValid(string s) {
        queue<string> q;
        map<string,int> visit;
        q.push(s);
        while(!q.empty()) {
            string t = q.front();
            q.pop();
            visit[t] = 1;
            if(isValidString(t)) {
                return t;
            }
            for(int i=0;i<t.length();i++) {
                if(t[i]!='(' && t[i]!=')')
                    continue;
                string w = t.substr(0,i) + t.substr(i+1);
                if(visit.find(w) == visit.end()) {
                    //cout<<w<<"\n";
                    q.push(w);
                }
            }
        }
        return s;
    }
};
//optimize
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='(') {
                st.push(i);
            } else if(s[i]==')') {
                if(!st.empty()) st.pop();
                else s[i] = '*';
            }
        }
        while(!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        string ans = "";
        for(int i=0;i<s.length();i++) {
            if(s[i] != '*')
                ans += s[i];
        }
        return ans;
    }
};