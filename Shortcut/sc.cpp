#include <bits/stdc++.h>
#define DEBUG true
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using namespace std;
inline int read(){
    int x = 0, f = 1;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c=='-') f = -1;
        c = getchar();
    }
    while(c>='0' && c <= '9'){
        x = (x<<1) + (x<<3) + (c^48);
        c = getchar();
    }
    return f*x;
}void setIO(string file = "")
{
    // speed up
    cin.tie(0)->sync_with_stdio(0);
    if ((int)(file.size()))
    {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}

inline void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}
/*
5 6 2
1 2 3 4 5
1 2 5
1 3 3
2 4 3
3 4 5
4 5 2
3 5 7
*/
int n, m, t;
vector<vector<pair<int, int>>> adj;
vector<vector<int>> adjTree;
vector<int> pa, numcows, dist, sums;


void djk(){
    priority_queue<pair<int, int>> pq;
    dist[1]=0;
    pq.push({dist[1], 1});
    while (!pq.empty()){
        auto [d, node] =pq.top();
        pq.pop();

        if(-d != dist[node]) continue;
        
        for (auto [nei, w]: adj[node]){
            if (dist[node] + w < dist[nei]){
                dist[nei]=dist[node]+w;
                pa[nei] = node;
                pq.push({-dist[nei], nei});
            }
            if(dist[node] + w == dist[nei]){
                if (pa[nei] > node){
                    pa[nei] = node;
                    pq.push({-dist[nei],nei});
                } 
            }
        }
    }
}

int
dfs (int cur)
{
    sums=numcows;
    if (adjTree[cur].size () == 0)
        return sums[cur] = numcows[cur];

    for (int nbr : adjTree[cur]) {
        sums[cur] += dfs (nbr);
    }

    return sums[cur];
}

signed main() {
    setIO("C:\\Users\\kyler\\USACO\\Shortcut\\sc");
    cin>>n>>m>>t;
    adjTree.assign(n+1,{});
    sums.assign(n+1,{});
    adj.assign(n+1, {});
    numcows.assign(n+1, 0);
    pa.assign(n+1, -1);
    dist.assign(n+1, inf); //? maybe?
    for(int i=1;i<=n;i++){
        cin>>numcows[i];
    }
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    djk();
    
    for (int i = 2; i <= n; ++i) {
        adjTree[pa[i]].push_back (i);
    }
    
    dfs (1);

    int best=0;
    for(int i=1;i<=n;i++){
        best=max(best,sums[i]*(dist[i]-t)); //uh               maybe ? 
    }
    cout<<best;
}