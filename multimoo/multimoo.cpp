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
int n,best,bestx2;
vector<vector<int>>arr;
vector<vector<int>>demo;
vector<vector<bool>>visited;
set<int>col;
set<pair<int,int>>border;
vector<int>color;
vector<pair<int,int>>bord;
bool inbound(int i,int j){
    return i>=0&&j>=0&&i<n&&j<n;
}
int ff(int i,int j,int c){
    int cnt=0;
    if(!inbound(i,j)||arr[i][j]!=c||visited[i][j]){
        if(inbound(i,j)&&arr[i][j]!=c){
            border.insert({arr[i][j],c});
        }
        return cnt;
    }
    visited[i][j]=true;
    cnt+=ff(i+1,j,c);
    cnt+=ff(i-1,j,c);
    cnt+=ff(i,j+1,c);
    cnt+=ff(i,j-1,c);
    return cnt+1;
}
int ff2(int i,int j,int c,int c2){
    int cnt=0;
    if(!inbound(i,j)||(arr[i][j]!=c&&arr[i][j]!=c2)||visited[i][j]){
        return cnt;
    }
    visited[i][j]=true;
    cnt+=ff2(i+1,j,c,c2);
    cnt+=ff2(i-1,j,c,c2);
    cnt+=ff2(i,j+1,c,c2);
    cnt+=ff2(i,j-1,c,c2);
    return cnt+1;
}
int main(){
    setIO("multimoo");
    cin>>n;
    arr.resize(n,vector<int>(n,0));
    demo.resize(n,vector<int>(n,0));
    visited.resize(n,vector<bool>(n,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            col.insert(arr[i][j]);
        }
    }
    //single moo greatest
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            best=max(best,ff(i,j,arr[j][j]));
        }
    }
    cout<<best<<endl;
    for(auto u:border){
        bord.push_back(u);
        cout<<u.first<<" "<<u.second<<endl;
    }
    for(int i=0;i<bord.size();i++){
        for(int k=0;k<n;k++){
            for(int l=0;l<n;l++){
                visited[k][l]=false;
            }
        }
        for(int k=0;k<n;k++){
            for(int l=0;l<n;l++){
                bestx2=max(bestx2,ff2(k,l,bord[i].first,bord[i].second));
            }
        }
    }
    cout<<bestx2<<endl;
}