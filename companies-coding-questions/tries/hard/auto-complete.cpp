#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
    unordered_map<char, TrieNode*> next;
    bool isWord;
    vector<pair<string, int>> words;
};

TrieNode* getNode() {
    TrieNode* node = new TrieNode();
    node->isWord = false;
    return node;
}
void addWord(TrieNode* start,string s, int score) {
    TrieNode* cur;
    cur = start;
    for(int i=0;i<s.length();i++) {
        char c = s[i];
        if(cur->next[c] == nullptr) {
            cur->next[c] = getNode();
        }
        cur = cur->next[c];
        if(cur->words.size() < 5) {
            cur->words.push_back({s,score});
        } else if(cur->words.back().second < score){
            cur->words.pop_back();
            cur->words.push_back({s,score});
        }
        sort(cur->words.begin(), cur->words.end(), [](auto a, auto b) {
            return a.second > b.second;
        });
    }
    cur->isWord = true;
}

TrieNode* getMatchedNode(TrieNode* root, string str, int sI) {
    if(sI == str.length()) {
        return root;
    }

    if(root->next.find(str[sI]) != root->next.end() and root->next[str[sI]] != nullptr) {
        return getMatchedNode(root->next[str[sI]], str, sI+1);
    }
    return nullptr;
}

int main()  {
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        vector<string> A,B;
        vector<int> W;
        string s;
        for(int i=0;i<n;i++) {
            cin>>s;
            A.push_back(s);
        }
        int p;
        for(int i=0;i<n;i++) {
            cin>>p;
            W.push_back(p);
        }
        TrieNode* root = getNode();
        for(int i=0;i<n;i++) {
            addWord(root, A[i], W[i]);
        }
        for(int i=0;i<m;i++) {
            cin>>s;
            TrieNode* startPoint = getMatchedNode(root, s, 0);
            if(startPoint == nullptr) {
                cout<<"-1 \n";
                continue;
            }
            for(auto a: startPoint->words) {
                cout<<a.first<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}