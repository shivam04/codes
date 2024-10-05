class Solution {
public:
    string simplifyPath(string path) {
        stack<string>s;
        string res;
        string dir;
        res = "";
        for(int i=0;i<path.length();i++){
            dir.clear();
            while(i < path.length() and path[i]=='/')
                i++;
            while (i < path.length() and path[i]!='/') {
                dir.push_back(path[i++]);
            }
            if (dir == "..") {
                if (!s.empty())
                    s.pop();
            }
            else if (dir == ".") {
                continue;
            }
            else if (dir.length() > 0) {
                s.push(dir);
            }
        }
        if (s.empty()) {
            return "/";
        }

        while(!s.empty()){
            string t = s.top();
            res = "/"+t+res;
            s.pop();
        }
        return res;
    }
};