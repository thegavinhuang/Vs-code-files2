#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "")
{
    // speed up
    cin.tie(0)->sync_with_stdio(0);
    if ((int)(file.size()))
    {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
//try 1 indexing everything if doesn't work
int n;
set<int>use;
vector<int>pot,visited,l;
vector<int>adj[100010];
void leaves(int s,int p){
    if(adj[s].size()==1&&s!=1){
        use.insert(s);
        return;
    }
    for(auto u:adj[s]){
        if(u!=p){
            leaves(u,s);
        }
    }
}
int dpforsure(int s,int p,int c){
    if(visited[s]!=0){
        c++;
        visited[s]--;
    }
    if(adj[s].size()==1&&s!=1){
        l[s]++;
        return c;
    }
    for(auto u:adj[s]){
        if(u!=p){
            int tmp=dpforsure(u,s,c);
            l[s]+=l[u];
            c+=min(tmp,l[s]);
        }
    }
    if(s==1){
        cout<<min(l[s],c)<<endl;
    }
    return min(l[s],c);
}
int main(){
    setIO("pf");
    cin>>n;
    pot.resize(n+1,0);
    visited.resize(n+1,0);
    l.resize(n+1,0);
    for(int i=0;i<n;i++){
        cin>>pot[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    leaves(1,0);
    for(int i=0;i<use.size();i++){
        visited[pot[i]]++;
    }
    dpforsure(1,0,0);
}