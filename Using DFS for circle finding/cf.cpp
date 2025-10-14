#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if ((int)(file.size())) {
      freopen((file + ".in").c_str(), "r", stdin);
      freopen((file + ".out").c_str(), "w", stdout);
    }
}
int n,m,st,ed;
vector<char>visited;
vector<bool>vis;
vector<int>adj[200100],parent;
void dfs(int s,int p){
    if(visited[s]=='b'){
        return;
    }
    visited[s]='g';
    for(auto u:adj[s]){
        if(u!=p&&visited[u]!='b'){
            if(visited[u]=='g'){
                st=s;
                ed=u;
            }
            dfs(u,s);
        }
        else{
            continue;
        }
    }
    visited[s]='b';
}
void findit(int s,int p,vector<int>arr){
    arr.push_back(s);
    vis[s]=true;
    if(s==ed){
        parent=arr;
        return;
    }
    for(auto u:adj[s]){
        if(!vis[u]&&u!=p){
            findit(u,s,arr);
        }
    }
}
int main(){
    freopen("C:\\Users\\kyler\\.vscode\\USACO\\Using DFS for circle finding\\cf.in","r",stdin);
    cin>>n>>m;
    visited.assign(n,'w');
    vis.assign(n,false);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(visited[i]=='w'){
            dfs(i,-1);
        }
    }
    findit(st,-1,parent);
    cout<<parent.size()<<endl;
    for(int i=0;i<parent.size();i++){
        cout<<parent[i]<<" ";
    }
}