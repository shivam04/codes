#define SIZE 100000 + 1

vector < pair < int , int > > v [SIZE];   // each vertex has all the connected vertices with the edges weights
int dist [SIZE];
bool vis [SIZE];

void dijkstra(){
                                                // set the vertices distances as infinity
    memset(vis, false , sizeof vis);            // set all vertex as unvisited
    dist[1] = 0;
    multiset < pair < int , int > > s;          // multiset do the job as a min-priority queue

    s.insert({0 , 1});                          // insert the source node with distance = 0

    while(!s.empty()){

        pair <int , int> p = *s.begin();        // pop the vertex with the minimum distance
        s.erase(s.begin());

        int x = p.s; int wei = p.f;
        if( vis[x] ) continue;                  // check if the popped vertex is visited before
         vis[x] = true;

        for(int i = 0; i < v[x].size(); i++){
            int e = v[x][i].f; int w = v[x][i].s;
            if(dist[x] + w < dist[e]  ){            // check if the next vertex distance could be minimized
                dist[e] = dist[x] + w;
                s.insert({dist[e],  e} );           // insert the next vertex with the updated distance
            }
        }
    }
}





vector<int> dijkstra(int source, vector<vector<pair<int, int> > > G)    {
    int INF = (int)1e9;
    int n = G.size();
    vector<int> D(n, INF);
    D[source] = 0;
    set<pair<int, int> > Q;
    Q.insert({0,source});
    while(!Q.empty())   {
        auto top = Q.begin();
        int u = top->second;
        Q.erase(top);
        for(auto next: G[u])    {
            int v = next.first, weight = next.second;
            if( D[u] + weight < D[v] ) {
                Q.erase(Q.find( {D[v], v} ));
                D[v] = D[u] + weight;
                Q.insert( {D[v], v} );
            }
        }
    }
    return D;
}