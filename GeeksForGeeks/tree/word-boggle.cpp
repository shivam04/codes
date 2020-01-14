#include<bits/stdc++.h>
using namespace std;
#define M 7
#define N 7
#define char_int(c) ((int)c - (int)'A')
map<string,int> see;
struct TrieNode
{
    TrieNode *next[52];
    bool word;
};
TrieNode *getNode()
{
    TrieNode * newNode = new TrieNode;
    newNode->word = false;
    for (int i =0 ; i< 52 ; i++)
        newNode->next[i] = NULL;
    return newNode;
}
void addWord(TrieNode* start,string s)
{
	TrieNode* cur;
	cur = start;
	for (int i = 0; i < s.size(); i++) {
	    int ch;
	    if(s[i]>='A' and s[i]<='Z'){
	        ch = char_int(s[i]);
	    }else{
	        ch = char_int(toupper(s[i]))+26;
	    }
		if (cur -> next[ch] == NULL) {
			cur -> next[ch] = getNode();
		}
		cur = cur -> next[ch];
	}
	cur -> word = true;
}
int valid(int i,int j,int m,int n){
    if(i>=0 and i<m and j>=0 and j<n)
    return 1;
    return 0;
}
int pos[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{0,-1},{1,-1},{1,0},{1,1}};
void dfs(TrieNode *root,int i,int j,int m,int n,int visit[M][N],char a[M][N],string str){
    if(root->word){
        see[str]=1;
        //cout<<str<<" ";
    }
    if(valid(i,j,m,n) and !visit[i][j]){
        visit[i][j] = 1;
        for(int o=0;o<52;o++){
            if(root->next[o]!=NULL){
                char ch;
                if(o<26)
                ch = 'A'+o;
                else
                ch = tolower('A'+o-26);
                for(int h=0;h<8;h++){
                    int x = i+pos[h][0];
                    int y = j+pos[h][1];
                    if(valid(x,y,m,n) and !visit[x][y] and root->next[o]!=NULL and a[x][y]==ch){
                        dfs(root->next[o],x,y,m,n,visit,a,str+ch);
                    }
                }   
            }
        }
        
        visit[i][j] = 0;
    }
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int er;
	    cin>>er;
	    string s[er+1];
	    string p;
	    TrieNode *root = getNode();
	    for(int i=0;i<er;i++){
	        cin>>p;
	        s[i] = p;
	        addWord(root,p);
	    }
	    int m,n;
	    cin>>m>>n;
	    int visit[M][N];
	    char a[M][N];
	    see.clear();
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            cin>>a[i][j];
	            visit[i][j] = 0;
	        }
	    }
	    string str = "";
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            int ch;
        	    if(a[i][j]>='A' and a[i][j]<='Z'){
        	        ch = char_int(a[i][j]);
        	    }else{
        	        ch = char_int(toupper(a[i][j]))+26;
        	    }
        	   // cout<<(root->next[ch]!=NULL)<<"\n";
	            if(root->next[ch]!=NULL){
	                str = str+a[i][j];
	                //cout<<str<<"\n";
	                dfs(root->next[ch],i,j,m,n,visit,a,str);    
	                str="";
	            }
	            
	        }
	    }
	    if(see.size()==0){
	        cout<<"-1\n";
	        continue;
	    }
	   // cout<<see.size()<<"\n";
	    vector<string> ans;
	    for(int i=0;i<er;i++){
	        //cout<<s[i]<<" "<<see[s[i]]<<"\n";
	        if(see[s[i]]==1){
	            ans.push_back(s[i]);
	            see[s[i]]=0;
	        }
	    }
	    sort(ans.begin(),ans.end());
	    for(int i=0;i<ans.size();i++){
	        cout<<ans[i]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}