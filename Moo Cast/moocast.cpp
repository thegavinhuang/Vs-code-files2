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
int n,best,cnt;
vector<pair<int,pair<int,int>>>arr;
vector<int>adj[1000];
vector<bool>visited;
void dfs(int s){
    if(visited[s]){
        return;
    }
    cnt++;
    visited[s]=true;
    for(auto u:adj[s]){
        dfs(u);
    }
}
void res(){
    visited.assign(n,false);
}
int main(){
    setIO("moocast");
    cin>>n;
    arr.assign(n,{0,{0,0}});
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second.first>>arr[i].second.second;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                int x=abs(arr[i].first-arr[j].first);
                x*=x;
                int y=abs(arr[i].second.first-arr[j].second.first);
                y*=y;
                double dist=x+y;
                if(dist<=arr[i].second.second*arr[i].second.second){
                    adj[i].push_back(j);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        visited.assign(n,false);
        dfs(i);
        best=max(cnt,best);
        cnt=0;
    }
    cout<<best<<endl;
}