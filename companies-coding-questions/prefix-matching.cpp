bool match(string a, string b) {
    if(a.length() < b.length())
        return false;
    string t = a.substr(0,b.length());
    return (t==b);
}
vector<int> Solution::solve(vector<string> &A, string B) {
    vector<int> ans(2,-1);
    int l = 0;
    int h = A.size() - 1;
    while(l<=h) {
        int m = (l+h)/2;
        if(match(A[m],B)) {
            ans[0] = m;
            h = m-1;
        } else if(A[m] > B) {
            h = m-1;
        } else {
            l = m+1;
        }
    }
    l=0;
    h=A.size()-1;
    while(l<=h) {
        int m = (l+h)/2;
        if(match(A[m],B)) {
            ans[1] = m;
            l = m+1;
        } else if(A[m] > B) {
            h = m-1;
        } else {
            l = m+1;
        }
    }
    return ans;
}



//good solution but memory exception
class TrieNode {
    public:
    unordered_map<char, TrieNode*>next;
    int minIndex;
    int maxIndex;
};

TrieNode* getNode() {
    TrieNode* node = new TrieNode();
    node->minIndex = 10000000;
    node->maxIndex = -1;
    return node;
}
void addWord(TrieNode* start,string s, int i) {
    TrieNode* cur;
    cur = start;
    for(int i=0;i<s.length();i++) {
        char c = s[i];
        if(cur->next[c] == nullptr) {
            cur->next[c] = getNode();
        }
        cur = cur->next[c];
    }
    cur->minIndex = min(cur->minIndex,i);
    cur->maxIndex = max(cur->maxIndex,i);
}

TrieNode* getFirstNode(TrieNode* start, string B, int s) {
    if(s==B.length()) {
        return start;
    }
    TrieNode* cur = start;
    if(cur->next[B[s]] == nullptr) {
        return nullptr;
    }
    return getFirstNode(start->next[B[s]], B, s+1);
}

vector<int> minMaxIndex(TrieNode* start) {
    queue<TrieNode*> q;
    q.push(start);
    int ansMax = start->maxIndex;
    int ansMin = start->minIndex;
    while(!q.empty()) {
        TrieNode* u = q.front();
        q.pop();
        for(char c = 'a'; c<='z';c++) {
            if(u->next[c] != nullptr) {
                ansMin = min(u->next[c]->minIndex, ansMin);
                q.push(u->next[c]);
                break;
            }
        }
    }
    q.push(start);
    while(!q.empty()) {
        TrieNode* u = q.front();
        q.pop();
        for(char c = 'z'; c>='a';c--) {
            if(u->next[c] != nullptr) {
                ansMax = max(u->next[c]->maxIndex, ansMax);
                q.push(u->next[c]);
                break;
            }
        }
    }

    return {ansMin, ansMax};
}

vector<int> Solution::solve(vector<string> &A, string B) {
    TrieNode* start = getNode();
    for(int i=0;i<A.size();i++) {
        addWord(start, A[i], i);
    }
    TrieNode* firstNode = getFirstNode(start, B, 0);
    if(firstNode==nullptr)
        return {-1,-1};
    vector<int> ans;
    return minMaxIndex(firstNode);
}
