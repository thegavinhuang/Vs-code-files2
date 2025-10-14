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
int n,k;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
vector<vector<char>>arr;
vector<vector<bool>>visited;
bool inbound(int i,int j){
    return i>=0&&j>=0&&i<n&&j<10;
}
int ff(int i,int j,char c){
    int cnt=0;
    if(!inbound(i,j)||visited[i][j]||arr[i][j]!=c){
        return cnt;
    }
    visited[i][j]=true;
    if(inbound(i,j)&&arr[i][j]==c){
        cnt+=ff(i+1,j,c);
        cnt+=ff(i-1,j,c);
        cnt+=ff(i,j+1,c);
        cnt+=ff(i,j-1,c);
    }
    return cnt+1;
}
void rem(int i,int j,char c){
    if(!inbound(i,j)||!visited[i][j]||arr[i][j]!=c){
        return;
    }
    arr[i][j]='0';
    rem(i+1,j,c);
    rem(i-1,j,c);
    rem(i,j+1,c);
    rem(i,j-1,c);
    return;
}
void down(){
    vector<char>temp;
    for(int j=0;j<10;j++){
        for(int i=n-1;i>=0;i--){
            visited[i][j]=false;
            if(arr[i][j]!='0'){
                temp.push_back(arr[i][j]);
            }
        }
        while(temp.size()!=n){
            temp.push_back('0');
        }
        for(int i=n-1;i>=0;i--){
            arr[i][j]=temp[n-1-i];
        }
        temp.clear();
    }
}
int main() { 
  setIO("mooyomooyo");
  cin>>n>>k;
  arr.resize(n,vector<char>(10,' '));
  visited.resize(n,vector<bool>(10,false));
  for(int i=0;i<n;i++){
    for(int j=0;j<10;j++){
        cin>>arr[i][j];
    }
  }
  while(true){
    bool b=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            if(!visited[i][j]&&arr[i][j]!='0'){
                int cnt1=ff(i,j,arr[i][j]);
                if(cnt1>=k){
                    rem(i,j,arr[i][j]);
                    b=true;
                }
            }
        }
    }
    if(b==false){
        break;
    }
    down();
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<10;j++){
        cout<<arr[i][j];
    }
    cout<<endl;
  }
}