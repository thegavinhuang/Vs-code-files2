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
int n;
set<int>use;
vector<int>arr;
vector<int>adj[100010];
vector<int>visited,l;
void down(int s,int parent){
    if(adj[s].size()==1&&s!=0){
        use.insert(s);
        return;
    }
    for(auto u:adj[s]){
        if(u!=parent){
            down(u,s);
        }
    }
}
int dptrust(int s,int p){
    int c=0;
    if(visited[s]!=0){
        c+=visited[s];
        visited[s]=0;
    }
    if(adj[s].size()==1&&s!=0){
        l[s]++;
    }
    for(auto u:adj[s]){
        if(u!=p){
            c+=dptrust(u,s);
            l[s]+=l[u];
        }
    }
    return min(c,l[s]);
}
int main(){
    setIO();
    cin>>n;
    arr.resize(n,0);
    l.resize(n,0),
    visited.resize(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i]--;
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    down(0,-1);
    for(int i=0;i<use.size();i++){
        visited[arr[i]]++;
    }
    cout<<dptrust(0,-1)<<endl;
}