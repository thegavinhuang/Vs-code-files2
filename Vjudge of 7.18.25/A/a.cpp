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
int t;
vector<int>arr;
void solve(){
    int n,c;
    vector<int>cnt;
    vector<pair<int,int>>gaps;
    cin>>n>>c;
    arr.assign(n+1,0);
    cnt.assign(c+1,0);
    gaps.assign(c+1,{-1,-1});
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        int curr=i;
        int dist=i-cnt[curr]-1;
        if(dist>gaps[curr].second){
            if(dist>gaps[curr].first){
                gaps[curr].second=gaps[curr].first;
                gaps[curr].first=dist;
            }
            else{
                gaps[curr].second=dist;
            }
        }
    }
    int best=INT_MAX;
    for(int i=1;i<=c;i++){
        if(gaps[i].second==-1){
            if(gaps[i].first!=-1){
                best=min(best,gaps[i].first);
            }
        }
        else{
            best=min(best,gaps[i].second);
        }
    }
    cout<<best<<endl;
}
int main(){
    setIO("C:\\Users\\kyler\\USACO\\Vjudge of 7.18.25\\A\\a");
    cin>>t;
    while(t--){
        solve();
    }
}