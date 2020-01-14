// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/
bool isCyclicutil(int s, int visit[], vector<int> adj[], int V){
    queue<int> q;
    q.push(s);
    visit[s] = 1;
    int parent[V];
    memset(parent, -1, sizeof(parent));
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i=0;i<adj[x].size();i++) {
            int y = adj[x][i];
            if(!visit[y]) {
                q.push(y);
                visit[y] = 1;
                parent[y] = x;
            }else if(parent[x]!=y) {
                return true;
            }
        }
    }
    return false;
}
bool isCyclic(vector<int> adj[], int V){
    int visit[V];
    memset(visit, 0, sizeof(visit));
    for(int i=0;i<V;i++) {
        if(!visit[i] and isCyclicutil(i,visit,adj,V)) {
            return true;
        }
    }
    return false;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends