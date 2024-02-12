#include<bits/stdc++.h>
using namespace std;
class TrieNode {
    public:
        map<char, TrieNode*> next;
        bool isWord;
        string word;
        vector<int> idx;
};

TrieNode* getNode(char c) {
    TrieNode* node = new TrieNode();
    node->isWord = false;
    node->word = "";
    return node;
}

void addWord(TrieNode* start, string s, int i) {
    TrieNode* curr;
    curr = start;
    for (int i=0;i<s.length();i++) {
        char c = s[i];
        if (curr->next[c] == nullptr) {
            curr->next[c] = getNode(c);
        }
        curr = curr->next[c];
    }
    curr->isWord = true;
    curr->word = s;
    curr->idx.push_back(i);
}

long long getNextWordsCount(TrieNode* start, int i) {
    if (start->next.size() == 0) {
        return 0;
    }
    
    queue<TrieNode*> q;
    q.push(start);
    
    int p = lower_bound(start->idx.begin(), start->idx.end(), i) - start->idx.begin();
    long long ans = p;
    
    while(!q.empty()) {
        TrieNode* t = q.front();
        q.pop();
        
        for (auto n: t->next) {
            ans += (n.second->isWord ? 1 : 0);
            q.push(n.second);
        }   
        
    }
    return ans;
}

long long solution(vector<string> words) {
    TrieNode* start = getNode('$');
    int i = 0;
    for(string s: words) {
        string p = s;
        reverse(p.begin(), p.end());
        addWord(start, p, i);
        i++;
    }
    i = 0;
    long long ans = 0;
    for(string s: words) {
        string p = s;
        reverse(p.begin(), p.end());
        TrieNode* w = start;
        for(char c: p) {
            w = w->next[c];
        }
        if (w->isWord) {
            long long countWordNext = getNextWordsCount(w, i);
            ans += countWordNext;
        }
        i++;
    }
    return ans;
}

int main() {
	int l;
	cin>>l;
	vector<string> s;
	for(int i=0;i<l;i++) {
		string p;
		cin>>p;
		s.push_back(p);
	}
	cout<<solution(s);
}
