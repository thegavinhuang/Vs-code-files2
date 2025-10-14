#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "") {
  // speed up
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
int n,q,ans;
vector<pair<int,int>>adj[10000];
void dfs(int s,int r,int p){
    ans++;
    for(auto u:adj[s]){
        if(u.second>=r&&u.first!=p){
            dfs(u.first,r,s);
        }
    }
}
int main(){
    setIO("mootube");
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        dfs(b,a,-1);
        cout<<ans-1<<endl;
        ans=0;
    }
}