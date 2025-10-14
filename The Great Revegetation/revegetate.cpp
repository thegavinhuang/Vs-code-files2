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
int n,m,groups;
bool cant;
vector<int>S[100010];//CHANGE ME
vector<int>D[100010],val;
vector<bool>visited;
vector<bool>visited2;
void dfs(int s,int cnt){
    if(visited[s]){
        return;
    }
    visited[s]=true;
    for(auto u:S[s]){
        if(val[u]!=0&&val[u]!=val[s]){
            cant=true;
            return;
        }
        val[u]=cnt;
        dfs(u,cnt);
    }
    for(auto u:D[s]){
        if(val[u]!=0&&val[u]==val[s]){
            cant=true;
            return;
        }
        if(val[u]==0){
            if(cnt==1){
                val[u]=2;
            }
            else{
                val[u]=1;
            }
        }
        dfs(u,val[u]);
    }
}
int main(){
    setIO("revegetate");
    cin>>n>>m;
    visited.assign(n,false);
    visited2.assign(n,false);
    val.assign(1e5+7,0);
    for(int i=0;i<m;i++){
        char a;
        int b,c;
        cin>>a>>b>>c;
        b--;
        c--;
        if(a=='S'){
            S[b].push_back(c);
            S[c].push_back(b);
        }
        else{
            D[b].push_back(c);
            D[c].push_back(b);
        }
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,1);
            groups++;
        }
    }
    if(cant==true){
        cout<<0;
        return 0;
    }
    cout<<1;
    for(int i=0;i<groups;i++){
        cout<<0;
    }
}