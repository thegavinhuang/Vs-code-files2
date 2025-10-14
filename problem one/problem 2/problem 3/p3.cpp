#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
int n,k,st;
vector<pair<int,pair<int,char>>>d;
vector<vector<char>>arr,visited;
vector<int>ans;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
char dz[]={'D','U','L','R'};
char da[]={'U','D','R','L'};
bool inbound(int x,int y){
  return x>=0&&y>=0&&x<n&&y<n;
}
bool dfs(int x,int y){
  if(visited[x][y]=='c'||visited[x][y]=='n'){
    visited[x][y]='n';
    return false;
  }
  if(visited[x][y]=='y'){
    return true;
  }
  visited[x][y]='c';
  for(int i=0;i<4;i++){//good
    if(!inbound(x+dx[i],y+dy[i])&&(arr[x][y]=='?'||arr[x][y]==dz[i])){
      visited[x][y]='y';
      return true;
    }
  }
  for(int i=0;i<4;i++){
    if(arr[x][y]=='?'||arr[x][y]==dz[i]){
      bool tmp=dfs(x+dx[i],y+dy[i]);
      if(tmp==true){
        visited[x][y]='y';
        return true;
      }
    }
  }
  if(visited[x][y]=='c'){
    visited[x][y]='n';
  }
  return false;
}
void rid(int x,int y){
  if(visited[x][y]=='y'){
    return;
  }
  for(int i=0;i<4;i++){
    if(inbound(x+dx[i],y+dy[i])&&visited[x+dx[i]][y+dy[i]]=='y'&&(arr[x][y]=='?'||arr[x][y]==dz[i])){
      visited[x][y]='y';
      st++;
      break;
    }
    else if(!inbound(x+dx[i],y+dy[i])&&(arr[x][y]=='?'||arr[x][y]==dz[i])){
      visited[x][y]='y';
      st++;
      break;
    }
  }
  if(visited[x][y]=='n'){
    return;
  }
  for(int i=0;i<4;i++){
    if(inbound(x+dx[i],y+dy[i])&&(arr[x+dx[i]][y+dy[i]]=='?'||arr[x+dx[i]][y+dy[i]]==da[i])){
      if(visited[x+dx[i]][y+dy[i]]=='n'){
        rid(x+dx[i],y+dy[i]);
      }
    }
  }
}
int main(){
    setIO();
    cin>>n>>k;
    d.assign(k,{0,{0,'?'}});
    visited.assign(n,vector<char>(n,'?'));
    arr.assign(n,vector<char>(n,'?'));
    for(int i=0;i<k;i++){
      cin>>d[i].second.first>>d[i].first>>d[i].second.second;
      d[i].first--;
      d[i].second.first--;
      arr[d[i].first][d[i].second.first]=d[i].second.second;
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(visited[i][j]=='?'){
          dfs(i,j);
        }
        if(visited[i][j]=='y'){
          st++;
        }
      }
    }
    ans.push_back(n*n-st);
    for(int i=k-1;i>=0;i--){
      arr[d[i].first][d[i].second.first]='?';
      rid(d[i].first,d[i].second.first);
      ans.push_back(n*n-st);
    }
    for(int i=k-1;i>=0;i--){
      cout<<ans[i]<<endl;
    }
}